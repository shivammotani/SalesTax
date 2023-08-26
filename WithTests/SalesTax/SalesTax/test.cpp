#include "pch.h"
#include "D:\Other\Codes\Projects\SalesTax\SalesTaxReceipt\Item.cpp"
#include "D:\Other\Codes\Projects\SalesTax\SalesTaxReceipt\Receipt.cpp"


TEST(TestItemIsValid, TestName1)
{

    Receipt purchasedItems;

    Item item1("1 book at 12.49");
    Item item2("1 music CD at 14.99");
    Item item3("1 chocolate bar at 0.85");

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
    purchasedItems.printReceipt();

    ASSERT_EQ(output, capturedOutput.str());
    std::cout.rdbuf(originalOutput);
}

TEST(TestItemIsValid, TestName2)
{

    Receipt purchasedItems;

    Item item1("1 imported box of chocolates at 10.00");
    Item item2("1 imported bottle of perfume at 47.50");

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
    purchasedItems.printReceipt();

    ASSERT_EQ(output, capturedOutput.str());
    std::cout.rdbuf(originalOutput);
}

TEST(TestItemIsValid, TestName3)
{

    Receipt purchasedItems;

    Item item1("1 imported bottle of perfume at 27.99");
    Item item2("1 bottle of perfume at 18.99");
    Item item3("1 packet of headache pills at 9.75");
    Item item4("1 box of imported chocolates at 11.25");

 
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
    purchasedItems.printReceipt();

    ASSERT_EQ(output, capturedOutput.str());
    std::cout.rdbuf(originalOutput);
}


TEST(TestItemIsValid, TestName4)
{

    Receipt purchasedItems;

    Item item1("2 box of chocolates at 10.00");
    Item item2("1 imported bottle of perfume at 47.50");

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
    purchasedItems.printReceipt();

    ASSERT_EQ(output, capturedOutput.str());
    std::cout.rdbuf(originalOutput);
}
