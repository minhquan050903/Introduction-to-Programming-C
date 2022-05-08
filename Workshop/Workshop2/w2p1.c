/*
*****************************************************************************
                          Workshop - #2 (P1)
Full Name  : Tran Minh Quan Nguyen
Student ID#: 116796210
Email      : nguyen-tran-minh-qua@myseneca.ca
Section    : IPC144NRR
Authenticity Declaration:
I declare this submission is the result of my own work and has not been
shared with any other student or 3rd party content provider. This submitted
piece of work is entirely of my own creation.
*****************************************************************************
*/

#include <stdio.h>

int main(void)
{
    // You must use this variable in #3 data analysis section!
    const double testValue = 330.99;
    const int id_1 = 111, id_2 = 222, id_3 = 111;
    const char tax_1 = 'Y', tax_2 = 'N', tax_3 = 'N';
    const double price_1 = 111.49, price_2 = 222.99, price_3 = 334.49;
    double average_price ,price_diff;

    printf("Product Information\n");
    printf("===================\n");
    
    //Show details of the products
    printf("Product-1 (ID:%d)\n", id_1);
    printf("  Taxed: %c\n", tax_1);
    printf("  Price: $%.4lf\n\n", price_1); 

    printf("Product-2 (ID:%d)\n", id_2);
    printf("  Taxed: %c\n", tax_2);
    printf("  Price: $%.4lf\n\n", price_2);

    printf("Product-3 (ID:%d)\n", id_3);
    printf("  Taxed: %c\n", tax_3);
    printf("  Price: $%.4lf\n\n", price_3); 

    // Calculating average : 
    average_price = (price_1 + price_2 + price_3) / 3;
    printf("The average of all prices is: $%.4lf\n\n",average_price);

    //Declareation about the expressions :
    printf("About Relational and Logical Expressions!\n");
    printf("========================================\n");
    printf("1. These expressions evaluate to TRUE or FALSE\n");
    printf("2. FALSE: is always represented by integer value 0\n");
    printf("3. TRUE : is represented by any integer value other than 0\n\n"); 

    // Analysis data :
    printf("Some Data Analysis...\n");
    printf("=====================\n");
    printf("1. Is product 1 taxable? -> %d\n\n", tax_1=='Y');
    printf("2. Are products 2 and 3 both NOT taxable (N)? -> %d\n\n",tax_2!='Y' && tax_3!='Y');
    printf("3. Is product 3 less than testValue ($%.2lf)? -> %d\n\n", testValue, price_3 < testValue);
    printf("4. Is the price of product 3 more than both product 1 and 2 combined? -> %d\n\n",price_3 > (price_1+ price_2));
    price_diff = price_3 - price_2; //calculating difference
    printf("5. Is the price of product 1 equal to or more than the price difference\n   of product 3 LESS product 2? ->  %d (price difference: $%.2lf)\n\n",price_1>=price_diff,price_diff);
    printf("6. Is the price of product 2 equal to or more than the average price? -> %d\n\n",price_2 >= average_price);
    printf("7. Based on product ID, product 1 is unique -> %d\n\n", id_1 != id_2 && id_1 != id_3);
    printf("8. Based on product ID, product 2 is unique -> %d\n\n", id_2 != id_1 && id_2 != id_3);
    printf("9. Based on product ID, product 3 is unique -> %d\n\n", id_3 != id_1 && id_3 != id_2);
    return 0;
}