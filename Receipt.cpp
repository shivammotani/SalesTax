#include <vector>
#include <iostream>
#include <string>
#include <iomanip>
#include "Item.h"
#include "Receipt.h"

// Default constructor for the Receipt class
Receipt::Receipt(){};

// Member function to add an item to the receipt
void Receipt::addItem(const Item &item)
{
        if (item.isValid())
        {
                // Add the valid item to the items vector
                items.emplace_back(item);

                // Update totalTax and totalCost based on the added item
                totalTax += item.calculateSalesTax();
                totalCost += item.getTotalPrice();
        }
        else
        {
                // If the item is invalid, throw an exception with a message
                throw std::invalid_argument("Invalid item.");
        }
}

// Member function to print the receipt
void Receipt::printReceipt() const
{
        int counter = 1;
        for (const Item &item : items)
        {
                std::cout << counter << ". ";
                item.printItem();
                ++counter;
        }
        std::cout << "Sales Taxes: " << std::fixed << std::setprecision(2) << totalTax << std::endl;
        std::cout << "Total: " << totalCost << std::endl;
}
