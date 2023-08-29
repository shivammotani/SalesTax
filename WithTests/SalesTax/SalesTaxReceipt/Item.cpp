#include <vector>
#include <string>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cmath>
#include "./Headers/item.h"

Item::Item(const int quantity, const double price, const std::string& itemName, bool isImported, bool isExempt)
{
    this->quantity = quantity;
    this->price = price;
    this->itemName = itemName;
    this->isImported = isImported;
    this->isExempt = isExempt;

}

int Item::getQuantity() const {
    return quantity;
}
double Item::getPrice() const {
    return price;
}
std::string Item::getItemName() const {
    return itemName;
}
double Item::getIsImported() const {
    return isImported;
}
double Item::getIsExempt() const {
    return isExempt;
}


