#ifndef inputsanitizer
#define inputsanitizer

#include<string>
#include<vector>

class SanitizeUserInput {
public:
    SanitizeUserInput(const std::string& itemDescription);
    bool isStringCorrect();
    int getQuantity();
    double getPrice();
    std::string getItemName();
    
    bool getIsExempt();
    bool getIsImported();

private:
    int quantity = -1;
    double price = -1;
    std::string itemName = "";
    bool isValid = true;
    bool isImported = false;
    bool isExempt = false;
    std::vector<std::string> exemptionList{ "food", "chocolate", "book", "medical", "pill", "medicine", "sandwich", "pizza" };
    void determineTaxStatus();

};

#endif

