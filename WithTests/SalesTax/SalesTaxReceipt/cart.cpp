#include <vector>
#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
#include "./Headers/item.h"
#include "./Headers/cart.h"
#include "./Headers/calculateTax.h"

Cart::Cart(){};

void Cart::addItem(const Item &item)
{
    
    setTotalCost(item);
    items.emplace_back( item, currentItemPriceIncludingTax);
    
}
double Cart::getTotalCost() const {
    return totalCost;
}

double Cart::getTotalTax() const {
    return totalTax;
}

std::vector<std::pair<Item, double>> Cart::getItems() const{
    return items;
}

void Cart::setTotalCost(const Item &item) 
{
    TaxCalculation tax;
    double taxOfCurrentItem = tax.calculateSalesTax(item);
    currentItemPriceIncludingTax = (item.getQuantity() * item.getPrice()) + taxOfCurrentItem;
    totalTax += taxOfCurrentItem;
    totalCost += (item.getQuantity() * item.getPrice()) + taxOfCurrentItem;
}