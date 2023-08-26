#ifndef Items
#define Items

#include <vector>
#include <string>

// Declaration of the Item class
class Item
{
public:
        // Constructor for creating an Item object
        Item(const std::string &itemDescription);

        // Function to check if the Item is valid (parsed correctly)
        bool isValid() const;

        // Function to print the item details
        void printItem() const;

        // Function to calculate the sales tax for the item
        double calculateSalesTax() const;

        // Function to get the total price of the item (including tax)
        double getTotalPrice() const;

public:
        // Member variables to store item information
        int quantity = -1;         // The quantity of the item
        double price = -1;         // The price of the item
        bool isImported = false;   // Indicates if the item is imported
        bool isExempt = false;     // Indicates if the item is tax-exempt
        bool isStringValid = true; // Indicates if the item description string is valid
        std::string itemName;      // The name of the item
        std::vector<std::string> exemptionList{"food", "chocolate", "book", "medical", "pill", "medicine", "sandwich", "pizza"};

        // Function to parse the item description string
        void parseItemDescription(const std::string &itemDescription);

        // Function to determine tax status based on item name
        void determineTaxStatus();

        // Function to round up a double value to the nearest 5 cents
        double roundUpToNearest5Cents(double amount) const;
};

// End of the class declaration

// End of the #ifndef block, ensuring the code is included only once

#endif
