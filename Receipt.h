#ifndef Receipts
#define Receipts

#include <vector>

class Receipt
{
public:
        Receipt();
        void addItem(const Item &item);
        void printReceipt() const;

private:
        std::vector<Item> items;
        double totalTax = 0.0;
        double totalCost = 0.0;
};

#endif
