#include <iostream>
#include <string>
#include <cmath>
#include <sstream>
#include "Item.h"
#include "Receipt.h"

int main()
{

        int totalItems, counter = 1;
        Receipt purchasedItems; // Create a Receipt object to store purchased items
        std::cout << "Enter total items: ";
        std::cin >> totalItems;

        std::cout << "Enter the products below: " << std::endl;
        while (totalItems)
        {
                std::cout << counter << ". ";
                std::string itemString;
                std::getline(std::cin >> std::ws, itemString); // Read the item description string
                Item entry(itemString);
                try
                {
                        purchasedItems.addItem(entry); // Add the item to the receipt
                        --totalItems;
                        ++counter;
                }
                catch (const std::invalid_argument &e)
                {
                        std::cout << "Input String is invalid. Kindly re-enter" << std::endl;
                }
        }
        std::cout << "END " << std::endl;

        // Print the receipt with item details, taxes, and total cost
        purchasedItems.printReceipt();

        return 0;
}
