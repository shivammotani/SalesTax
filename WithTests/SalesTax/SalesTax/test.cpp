#include "pch.h"
#include "../SalesTaxReceipt/item.cpp"
#include "../SalesTaxReceipt/cart.cpp"
#include "../SalesTaxReceipt/receiptPrinter.cpp"
#include "../SalesTaxReceipt/calculateTax.cpp"

TEST(TestItemIsValid, TestName1)
{

    Cart purchasedItems;
    ReceiptPrinter printer;
    Item item1(1, 12.49, "book", false, true);
    Item item2(1, 14.99, "music CD", false, false);
    Item item3(1, 0.85, "chocolate bar", false, true);

    purchasedItems.addItem(item1);
    purchasedItems.addItem(item2);
    purchasedItems.addItem(item3);

    std::string output;
    output = "1. 1 book: 12.49\n"
        "2. 1 music CD: 16.49\n"
        "3. 1 chocolate bar: 0.85\n"
        "Sales Taxes: 1.50\n"
        "Total: 29.83\n";

    std::ostringstream capturedOutput;
    std::streambuf* originalOutput = std::cout.rdbuf();
    std::cout.rdbuf(capturedOutput.rdbuf());
    printer.printReceipt(purchasedItems);

    ASSERT_EQ(output, capturedOutput.str());
    std::cout.rdbuf(originalOutput);
}

TEST(TestItemIsValid, TestName2)
{

    Cart purchasedItems;
    ReceiptPrinter printer;

    Item item1(1, 10.00, "imported box of chocolates", true, true);
    Item item2(1, 47.50, "imported bottle of perfume", true, false);

    purchasedItems.addItem(item1);
    purchasedItems.addItem(item2);

    std::string output;
    output = "1. 1 imported box of chocolates: 10.50\n"
        "2. 1 imported bottle of perfume: 54.65\n"
        "Sales Taxes: 7.65\n"
        "Total: 65.15\n";

    std::ostringstream capturedOutput;
    std::streambuf* originalOutput = std::cout.rdbuf();
    std::cout.rdbuf(capturedOutput.rdbuf());
    printer.printReceipt(purchasedItems);

    ASSERT_EQ(output, capturedOutput.str());
    std::cout.rdbuf(originalOutput);
}

TEST(TestItemIsValid, TestName3)
{

    Cart purchasedItems;
    ReceiptPrinter printer;

    Item item1(1, 27.99, "imported bottle of perfume", true, false);
    Item item2(1, 18.99, "bottle of perfume", false, false);
    Item item3(1, 9.75, "packet of headache pills", false, true);
    Item item4(1, 11.25, "box of imported chocolates", true, true);

    purchasedItems.addItem(item1);
    purchasedItems.addItem(item2);
    purchasedItems.addItem(item3);
    purchasedItems.addItem(item4);

    std::string output;
    output = "1. 1 imported bottle of perfume: 32.19\n"
        "2. 1 bottle of perfume: 20.89\n"
        "3. 1 packet of headache pills: 9.75\n"
        "4. 1 box of imported chocolates: 11.85\n"
        "Sales Taxes: 6.70\n"
        "Total: 74.68\n";

    std::ostringstream capturedOutput;
    std::streambuf* originalOutput = std::cout.rdbuf();
    std::cout.rdbuf(capturedOutput.rdbuf());
    printer.printReceipt(purchasedItems);

    ASSERT_EQ(output, capturedOutput.str());
    std::cout.rdbuf(originalOutput);
}


TEST(TestItemIsValid, TestName4)
{

    Cart purchasedItems;
    ReceiptPrinter printer;

    Item item1(2, 10.00, "box of chocolates", false, true);
    Item item2(1, 47.50, "imported bottle of perfume", true, false);


    purchasedItems.addItem(item1);
    purchasedItems.addItem(item2);

    std::string output;
    output = "1. 2 box of chocolates: 20.00\n"
        "2. 1 imported bottle of perfume: 54.65\n"
        "Sales Taxes: 7.15\n"
        "Total: 74.65\n";

    std::ostringstream capturedOutput;
    std::streambuf* originalOutput = std::cout.rdbuf();
    std::cout.rdbuf(capturedOutput.rdbuf());
    printer.printReceipt(purchasedItems);

    ASSERT_EQ(output, capturedOutput.str());
    std::cout.rdbuf(originalOutput);
}
