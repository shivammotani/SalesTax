#include <vector>
#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
#include "./Headers/Item.h"
#include "./Headers/Receipt.h"

Receipt::Receipt(){};

void Receipt::addItem(const Item &item)
{
        if (item.isValid())
        {
                items.emplace_back(item);
                totalTax += item.calculateSalesTax();
                totalCost += item.getTotalPrice();
        }
        else
        {
                throw std::invalid_argument("Invalid item."); // Add exception
        }
}

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
