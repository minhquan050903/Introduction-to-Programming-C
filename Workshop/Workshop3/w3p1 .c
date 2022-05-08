/*
*****************************************************************************
                          Workshop - #3 (P1)
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

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int main(void)
{
    const double TAX = 0.13;
    const char patSize = 'S';
    double small_size_price, medium_size_price, large_size_price;
    int numbers_of_shirt;
    double sub_total , taxes ,rounded_taxes ,total ;
    int rounding_taxes;
    
    printf("Set Shirt Prices\n");
    printf("================\n");
    //Promt the price of 3 sizes
    printf("Enter the price for a SMALL shirt: $");
    scanf("%lf", &small_size_price); 

    printf("Enter the price for a MEDIUM shirt: $");
    scanf("%lf", &medium_size_price); 

    printf("Enter the price for a LARGE shirt: $");
    scanf("%lf", &large_size_price); 
    printf("\n");
    //Display the prices of 3 sizes
    printf("Shirt Store Price List\n");
    printf("======================\n");
    printf("SMALL  : $%.2lf\n",small_size_price);
    printf("MEDIUM : $%.2lf\n", medium_size_price);
    printf("LARGE  : $%.2lf\n\n", large_size_price);

    //Promt the numbers of patSize shirt
    printf("Patty's shirt size is '%c'\n", patSize);
    printf("Number of shirts Patty is buying: ");
    scanf("%d", &numbers_of_shirt); 
    printf("\n");
    //Checkout 
    printf("Patty's shopping cart...\n");
    printf("Contains : %d shirts\n", numbers_of_shirt);
    sub_total = small_size_price * numbers_of_shirt;
    taxes = sub_total * TAX;                         
    rounding_taxes = taxes * 100 +0.5;                  
    rounded_taxes = (double)rounding_taxes / 100;
    total = sub_total + rounded_taxes;
    printf("Sub-total: $%8.4lf\n", sub_total); 
    printf("Taxes    : $%8.4lf\n",rounded_taxes);
    printf("Total    : $%8.4lf\n", total);


    return 0;
}

