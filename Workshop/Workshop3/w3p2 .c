/*
*****************************************************************************
                          Workshop - #3 (P2)
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
    const char patSize = 'S', salSize = 'M', tomSize = 'L';
    

        double small_size_price, medium_size_price, large_size_price;
        int numbers_of_patShirt, numbers_of_tomShirt, numbers_of_salShirt;
        double sal_sub_total, sal_taxes, sal_rounded_taxes, sal_total;
        double pat_sub_total, pat_taxes, pat_rounded_taxes, pat_total;
        double tom_sub_total, tom_taxes, tom_rounded_taxes, tom_total;
        int tom_rounding_taxes, sal_rounding_taxes, pat_rounding_taxes;
        double total_taxes, total_subtotal, final_total;
        int amountT_1, amountL_1, amountQ_1, amountD_1, amountN_1, amountP_1, balance_1;
        int remainingT_1, remainingL_1, remainingQ_1, remainingD_1, remainingN_1, remainingP_1;
        int valueT = 200, valueL = 100, valueQ = 25, valueD = 10, valueN = 5, valueP = 1;
        double remainingT_id_1, remainingL_id_1, remainingQ_id_1, remainingD_id_1, remainingN_id_1, remainingP_id_1;
        int amountT_2, amountL_2, amountQ_2, amountD_2, amountN_2, amountP_2, balance_2;
        int remainingT_2, remainingL_2, remainingQ_2, remainingD_2, remainingN_2, remainingP_2;
        double remainingT_id_2, remainingL_id_2, remainingQ_id_2, remainingD_id_2, remainingN_id_2, remainingP_id_2;

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
        printf("SMALL  : $%.2lf\n", small_size_price);
        printf("MEDIUM : $%.2lf\n", medium_size_price);
        printf("LARGE  : $%.2lf\n\n", large_size_price);

        //Promt the numbers of patSize shirt
        printf("Patty's shirt size is '%c'\n", patSize);
        printf("Number of shirts Patty is buying: ");
        scanf("%d", &numbers_of_patShirt);
        printf("\n"); 

        printf("Tommy's shirt size is '%c'\n", tomSize);
        printf("Number of shirts Tommy is buying: ");
        scanf("%d", &numbers_of_tomShirt);
        printf("\n"); 

        printf("Sally's shirt size is '%c'\n", salSize);
        printf("Number of shirts Sally is buying: ");
        scanf("%d", &numbers_of_salShirt);
        printf("\n");
        
        //Rounding process
       
        sal_sub_total = medium_size_price * numbers_of_salShirt;
        sal_taxes = sal_sub_total * TAX;
        sal_rounding_taxes = sal_taxes * 100 + 0.5;
        sal_rounded_taxes = (double)sal_rounding_taxes / 100;
        sal_total = sal_sub_total + sal_rounded_taxes;

        tom_sub_total = large_size_price * numbers_of_tomShirt;
        tom_taxes = tom_sub_total * TAX;
        tom_rounding_taxes = tom_taxes * 100 + 0.5;
        tom_rounded_taxes = (double)tom_rounding_taxes / 100;
        tom_total = tom_rounded_taxes + tom_sub_total;

        pat_sub_total = small_size_price * numbers_of_patShirt;
        pat_taxes = pat_sub_total * TAX;
        pat_rounding_taxes = pat_taxes * 100 + 0.5;
        pat_rounded_taxes = (double)pat_rounding_taxes / 100;
        pat_total = pat_rounded_taxes + pat_sub_total;
        //Calculating total stats
        total_taxes = pat_rounded_taxes + tom_rounded_taxes + sal_rounded_taxes;
        total_subtotal = pat_sub_total+ tom_sub_total+ sal_sub_total;
        final_total = total_taxes + total_subtotal;
        //Display check out  
        printf("Customer Size Price Qty Sub-Total       Tax     Total\n");
        printf("-------- ---- ----- --- --------- --------- ---------\n");
        printf("Patty    %-4c %5.2lf %3d %9.4lf %9.4lf %9.4lf\n", patSize, small_size_price, numbers_of_patShirt, pat_sub_total, pat_rounded_taxes, pat_total);
        printf("Sally    %-4c %5.2lf %3d %9.4lf %9.4lf %9.4lf\n", salSize, medium_size_price, numbers_of_salShirt, sal_sub_total, sal_rounded_taxes, sal_total);
        printf("Tommy    %-4c %5.2lf %3d %9.4lf %9.4lf %9.4lf\n", tomSize, large_size_price, numbers_of_tomShirt, tom_sub_total, tom_rounded_taxes, tom_total);
        printf("-------- ---- ----- --- --------- --------- ---------\n");
        printf("%33.4lf %9.4lf %9.4lf\n\n", total_subtotal, total_taxes, final_total);
        balance_1 = total_subtotal * 100;

        amountT_1= balance_1 / valueT;
        remainingT_1 = balance_1 % valueT;

        amountL_1 = remainingT_1 / valueL;
        remainingL_1 = remainingT_1 % valueL;

        amountQ_1 = remainingL_1 / valueQ;
        remainingQ_1 = remainingL_1 % valueQ;

        amountD_1 = remainingQ_1 / valueD;
        remainingD_1 = remainingQ_1 % valueD;

        amountN_1 = remainingD_1 / valueN;
        remainingN_1 = remainingD_1 % valueN;

        amountP_1 = remainingN_1 / valueP;
        remainingP_1 = remainingN_1 % valueP;

        remainingT_id_1 = (double)remainingT_1 / 100;
        remainingL_id_1 = (double)remainingL_1 / 100;
        remainingQ_id_1 = (double)remainingQ_1 / 100;
        remainingD_id_1 = (double)remainingD_1 / 100;
        remainingN_id_1 = (double)remainingN_1 / 100;
        remainingP_id_1 = (double)remainingP_1 / 100;
        
        printf("Daily retail sales represented by coins\n");
        printf("=======================================\n\n");
        printf("Sales EXCLUDING tax\n");
        printf("Coin     Qty   Balance\n");
        printf("-------- --- ---------\n");
        printf("%22.4lf\n", total_subtotal);
        
        printf("Toonies  %3d %9.4lf\n", amountT_1, remainingT_id_1);
        printf("Loonies  %3d %9.4lf\n", amountL_1, remainingL_id_1);
        printf("Quarters %3d %9.4lf\n", amountQ_1, remainingQ_id_1);
        printf("Dimes    %3d %9.4lf\n", amountD_1, remainingD_id_1);
        
        printf("Nickels  %3d %9.4lf\n", amountN_1, remainingN_id_1);
        
        printf("Pennies  %3d %9.4lf\n\n", amountP_1, remainingP_id_1);

        printf("Average cost/shirt: $%.4lf\n\n", (double)(total_subtotal / (numbers_of_patShirt + numbers_of_salShirt + numbers_of_tomShirt))); 

        balance_2 = final_total * 100;

        amountT_2= balance_2 / valueT;
        remainingT_2 = balance_2 % valueT;

        amountL_2 = remainingT_2 / valueL;
        remainingL_2 = remainingT_2 % valueL;

        amountQ_2 = remainingL_2 / valueQ;
        remainingQ_2 = remainingL_2 % valueQ;

        amountD_2 = remainingQ_2 / valueD;
        remainingD_2 = remainingQ_2 % valueD;

        amountN_2 = remainingD_2 / valueN;
        remainingN_2 = remainingD_2 % valueN;

        amountP_2 = remainingN_2 / valueP;
        remainingP_2 = remainingN_2 % valueP;

        remainingT_id_2 = (double)remainingT_2 / 100;
        remainingL_id_2 = (double)remainingL_2 / 100;
        remainingQ_id_2 = (double)remainingQ_2 / 100;
        remainingD_id_2 = (double)remainingD_2 / 100;
        remainingN_id_2 = (double)remainingN_2 / 100;
        remainingP_id_2 = (double)remainingP_2 / 100;

       
        printf("Sales INCLUDING tax\n");
        printf("Coin     Qty   Balance\n");
        printf("-------- --- ---------\n");
        printf("%22.4lf\n", final_total);

        printf("Toonies  %3d %9.4lf\n", amountT_2, remainingT_id_2);
        printf("Loonies  %3d %9.4lf\n", amountL_2 ,remainingL_id_2);
        printf("Quarters %3d %9.4lf\n", amountQ_2, remainingQ_id_2);
        printf("Dimes    %3d %9.4lf\n", amountD_2, remainingD_id_2);

        printf("Nickels  %3d %9.4lf\n", amountN_2, remainingN_id_2);

        printf("Pennies  %3d %9.4lf\n\n", amountP_2, remainingP_id_2);

        printf("Average cost/shirt: $%.4lf\n\n", (double)(final_total / (numbers_of_patShirt + numbers_of_salShirt + numbers_of_tomShirt)));

       
    return 0;
}