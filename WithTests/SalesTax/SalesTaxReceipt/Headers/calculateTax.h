#pragma once

#include "./item.h"

class TaxCalculation {
public:
    double calculateSalesTax(const Item &item) const;

private:
    double roundUpToNearest5Cents(double amount) const;
};


