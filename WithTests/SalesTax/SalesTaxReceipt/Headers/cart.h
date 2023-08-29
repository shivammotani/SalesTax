#ifndef carts
#define carts

#include <vector>
#include "./item.h"

class Cart
{
public:     
        Cart();
        void addItem(const Item &item);
        std::vector<std::pair<Item, double>> getItems() const;
        double getTotalCost() const;
        double getTotalTax() const;

private:
        std::vector<std::pair<Item, double>> items;
        double totalCost = 0.0;
        double totalTax = 0.0;
        double currentItemPriceIncludingTax = 0.0;
        void setTotalCost(const Item &item);
    
};

#endif
