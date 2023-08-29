# Sales Tax App

# Intro

This is a C++ program that prints the total bill including the total tax

Follow the process below to run the code on your local machine

### Step 1: Clone the Repository

`git clone https://github.com/shivammotani/SalesTax.git`

### Step 2: There are two folders in the repository:
    a. noTests: This code will be easier to run as it only requires compilation
    b. withTests: This will require a couple of installations which are described below. I'll include some screenshots of the test cases at the bottom if you don't want to follow this process.

### Step 3: If you want to just compile and see the code in real follow the below steps:
    a. Make sure you have a C++ compiler installed. I'm using Mingw.
    b. Go to the noTests folder and execute the following commands:
    
`g++ .\main.cpp .\Item.cpp .\Receipt.cpp` 

`.\a.exe`

Once done it'll ask you to input the items one by one. Remember the input string should be in the following format:
   ##### `<Quantity Item_Description at Price>`    e.g string: "5 bottles of perfume at 18.99"
   
This format is mandatory as it'll help the code to identify the different parts of the string. If not it'll keep saying invalid string.
Type "quit" to print the total receipt.

### Step 4: If you want to run the test file follow the below steps:
    a. Install Visual Studio
    b. Make sure Google Test is selected as highlighted below

![Screenshot 2023-08-26 192434](https://github.com/shivammotani/SalesTax/assets/52162019/33806de3-8574-44d0-ab09-771ffcccc6fe)

    c. Click install and wait for the process to end.
    d. Go to file>Open>Project/Solution and open the withTests Directory
    e. Build and run the test.cpp file present in SalesTax Project



#### Here are some of the screenshots from the test file:

![image](https://github.com/shivammotani/SalesTax/assets/52162019/fcce6145-810d-46a3-9e34-85d1e7d02681)
![image](https://github.com/shivammotani/SalesTax/assets/52162019/08dd7882-2788-4db0-b91d-aeb42dc29592)
![image](https://github.com/shivammotani/SalesTax/assets/52162019/f8675d00-c0bb-47b6-a06b-7bd28361698d)

    
