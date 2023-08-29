#include "./Headers/inputSanitiser.h"
#include<string>
#include <sstream>
#include <vector>



SanitizeUserInput::SanitizeUserInput(const std::string& itemDescription) {
    std::istringstream parseTheString(itemDescription);
    parseTheString >> quantity;
    std::string keyword;
    while (parseTheString >> keyword)
    {
        if (keyword == "at")
        {
            parseTheString >> price;
            break;
        }
        itemName += keyword + " ";
    }
    itemName.pop_back(); // Remove trailing space
    determineTaxStatus();
    if (price == -1 || quantity == -1)
    {
        isValid = false;
    }
}

bool SanitizeUserInput::isStringCorrect() {
    return isValid;
}

int SanitizeUserInput::getQuantity() {
    return quantity;
}
double SanitizeUserInput::getPrice() {
    return price;
}
std::string SanitizeUserInput::getItemName() {
    return itemName;
}
bool SanitizeUserInput::getIsExempt() {
    return isExempt;
}
bool SanitizeUserInput::getIsImported() {
    return isImported;
}

void SanitizeUserInput::determineTaxStatus()
{
    if (itemName.find("import") != std::string::npos)
    {
        isImported = true;
    }

    // Check for tax exemption keywords
    for (std::string exempt : exemptionList)
    {
        if (itemName.find(exempt) != std::string::npos)
        {
            isExempt = true;
            break;
        }
    }

}