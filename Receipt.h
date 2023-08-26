#ifndef Receipts
#define Receipts

#include <vector>

// Declaration of a class named Receipt
class Receipt
{
public:
        // Constructor for creating a Receipt object
        Receipt();
        void addItem(const Item &item);
        void printReceipt() const;

private:
        // A vector to store items on the receipt
        std::vector<Item> items;

        // Variables to keep track of total tax and total cost
        double totalTax = 0.0;
        double totalCost = 0.0;
};

// End of the #ifndef block, ensuring the code is included only once
#endif
