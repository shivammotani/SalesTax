#include "./Headers/receiptPrinter.h"
#include "./Headers/item.h"
#include "./Headers/cart.h"
#include <iostream>
#include <iomanip>

void ReceiptPrinter::printReceipt(const Cart& cart) {
    int counter = 1;
    for (const std::pair<Item, double> items : cart.getItems()) {
        std::cout << counter << ". ";
        std::pair<Item, double> newItem = items;
        std::cout << newItem.first.getQuantity() << " " << newItem.first.getItemName() << ": " << std::fixed << std::setprecision(2) << newItem.second << std::endl;
        ++counter;
    }
    std::cout << "Sales Taxes: " << std::fixed << std::setprecision(2) << cart.getTotalTax() << std::endl;
    std::cout << "Total: " << cart.getTotalCost() << std::endl;
}
