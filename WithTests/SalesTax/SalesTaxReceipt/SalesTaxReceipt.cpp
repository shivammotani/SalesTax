#include <iostream>
#include <string>
#include <cmath>
#include <sstream>
#include "./Headers/item.h"
#include "./Headers/cart.h"
#include "./Headers/receiptPrinter.h"
#include "./Headers/inputSanitiser.h"

int main()
{

    int  counter = 1;
    Cart purchasedItems;
    ReceiptPrinter printer;
    std::cout << "This is new" << std::endl;
    std::cout << "Enter the items below. Enter 'quit' to print Receipt" << std::endl;
    while (true)
    {
        std::cout << counter << ". ";
        std::string itemString;
        std::getline(std::cin >> std::ws, itemString);
        
        if (itemString == "quit")
            break;
        SanitizeUserInput checkUserInput(itemString);
        try {
            if (checkUserInput.isStringCorrect()) {
                Item newItem(checkUserInput.getQuantity(), checkUserInput.getPrice(), checkUserInput.getItemName(), checkUserInput.getIsImported(), checkUserInput.getIsExempt());
                purchasedItems.addItem(newItem);
                ++counter;
            }
            else {
                std::cout << "Input String is invalid. Kindly re-enter" << std::endl;
            }
        }
        catch (const std::invalid_argument& e){
            std::cout << "Input String is invalid. Kindly re-enter" << std::endl;
        }
    }
    std::cout << std::endl;
    std::cout << "Here is the Receipt " << std::endl;
    std::cout << std::endl;
    printer.printReceipt(purchasedItems);

    return 0;
}
