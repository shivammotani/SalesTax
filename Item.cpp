#include <vector>
#include <string>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cmath>
#include "Item.h"

// Constructor for the Item class
Item::Item(const std::string &itemDescription)
{
        parseItemDescription(itemDescription);
}

// Function to check if the Item is valid (parsed correctly)
bool Item::isValid() const
{
        return isStringValid;
}

void Item::printItem() const
{
        std::cout << quantity << " " << itemName << ": " << std::fixed << std::setprecision(2) << getTotalPrice() << std::endl;
}

// Function to calculate the sales tax for the item
double Item::calculateSalesTax() const
{
        double tax = 0.0;
        if (!isExempt)
        { // Calculate Basic sales tax
                tax += price * 0.10;
        }
        if (isImported)
        { // Calculate Import duty
                tax += price * 0.05;
        }
        return roundUpToNearest5Cents(quantity * tax);
}

// Function to get the total price of the item (including tax)
double Item::getTotalPrice() const
{
        return (quantity * price) + calculateSalesTax();
}

// Function to parse the item description string
void Item::parseItemDescription(const std::string &itemDescription)
{
        std::istringstream parseTheString(itemDescription);
        parseTheString >> quantity;
        std::string keyword;
        while (parseTheString >> keyword)
        {
                if (keyword == "at")
                {
                        parseTheString >> price;
                        break;
                }
                itemName += keyword + " ";
        }
        itemName.pop_back(); // Remove trailing space
        if (price == -1 || quantity == -1)
        {
                isStringValid = false;
                return;
        }
        determineTaxStatus();
}

// Function to determine tax status based on item name
void Item::determineTaxStatus()
{
        if (itemName.find("import") != std::string::npos)
        {
                isImported = true;
        }

        // Check for tax exemption keywords
        for (std::string exempt : exemptionList)
        {
                if (itemName.find(exempt) != std::string::npos)
                {
                        isExempt = true;
                        break;
                }
        }
}

// Function to round up a double value to the nearest 0.05 cents
double Item::roundUpToNearest5Cents(double amount) const
{
        return std::ceil(amount * 20.0) / 20.0;
}
