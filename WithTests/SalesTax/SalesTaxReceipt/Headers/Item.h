#ifndef Items
#define Items

#include <vector>
#include <string>


class Item
{
public:
    Item(const int quantity, const double price, const std::string& itemName, bool isImported, bool isExempt);
    int getQuantity() const;
    double getPrice() const;
    std::string getItemName() const;
    double getIsImported() const;
    double getIsExempt() const;

private:
    int quantity = -1;
    double price = -1;
    std::string itemName;
    bool isImported = false;
    bool isExempt = false;        
};

#endif
