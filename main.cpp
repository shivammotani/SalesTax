#include <iostream>
#include <string>
#include <cmath>
#include <sstream>
#include "Item.h"
#include "Receipt.h"

int main()
{

        int totalItems, counter = 1;
        Receipt purchasedItems;
        std::cout << "Enter the items below. Enter 'quit' to print Receipt" << std::endl;
        while (true)
        {
                std::cout << counter << ". ";
                std::string itemString;
                std::getline(std::cin >> std::ws, itemString);
                if (itemString == "quit")
                        break;
                Item entry(itemString);
                try
                {
                        purchasedItems.addItem(entry);
                        --totalItems;
                        ++counter;
                }
                catch (const std::invalid_argument &e)
                {
                        std::cout << "Input String is invalid. Kindly re-enter" << std::endl;
                }
        }
        std::cout << std::endl;
        std::cout << "Here is the Receipt " << std::endl;
        std::cout << std::endl;
        purchasedItems.printReceipt();

        return 0;
}
