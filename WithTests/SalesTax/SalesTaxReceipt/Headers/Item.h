#ifndef Items
#define Items

#include <vector>
#include <string>


    class Item
    {
    public:
        Item(const std::string& itemDescription);
        bool isValid() const;
        void printItem() const;
        double calculateSalesTax() const;
        double getTotalPrice() const;

    public:
        int quantity = -1;
        double price = -1;
        bool isImported = false;
        bool isExempt = false;
        bool isStringValid = true;
        std::string itemName;
        std::vector<std::string> exemptionList{ "food", "chocolate", "book", "medical", "pill", "medicine", "sandwich", "pizza" };

        void parseItemDescription(const std::string& itemDescription);

        void determineTaxStatus();

        double roundUpToNearest5Cents(double amount) const;
    };

#endif
