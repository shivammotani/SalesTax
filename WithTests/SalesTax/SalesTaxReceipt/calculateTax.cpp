
#include <cmath>
#include "./Headers/item.h"
#include "./Headers/calculateTax.h"


double TaxCalculation::calculateSalesTax(const Item & item) const
{

    double tax = 0.0;
    if (!item.getIsExempt())
    { // Calculate Basic sales tax
        tax += item.getPrice() * 0.10;
    }
    if (item.getIsImported())
    { // Calculate Import duty
        tax += item.getPrice() * 0.05;
    }
    return roundUpToNearest5Cents(item.getQuantity() * tax);
}


double TaxCalculation::roundUpToNearest5Cents(double amount) const
{
    return std::ceil(amount * 20.0) / 20.0;
}