/*
*****************************************************************************
                          Workshop - #2 (P2)
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
    // You will need this when converting from grams to pounds (lbs)
    const double GRAMS_IN_LBS = 453.5924;
    char type_1, type_2, type_3;
    char grind_size_1, grind_size_2, grind_size_3;
    int  weight_g_1, weight_g_2, weight_g_3;
    char serving_w_cream_1, serving_w_cream_2, serving_w_cream_3;
    double ideal_temp_1, ideal_temp_2, ideal_temp_3;

    char coff_strength ,prefer_cream ,maker;
    int daily_serv_num;
    //Logical Expression variables 
    int c1, m1, d1, p1, i1 , c2, m2, d2, p2, i2 , c3, m3, d3, p3, i3;
    printf("Take a Break - Coffee Shop\n");
    printf("==========================\n\n");
    printf("Enter the coffee product information being sold today...\n\n");
    
    // Input data for Coffee 1 :
    printf("COFFEE-1...\n");
    
    printf("Type ([L]ight,[B]lend): "); 
    scanf(" %c", &type_1);

    printf("Grind size ([C]ourse,[F]ine): ");
    scanf(" %c", &grind_size_1);


    printf("Bag weight (g): ");
    scanf(" %d", &weight_g_1);
    
    printf("Best served with cream ([Y]es,[N]o): ");
    scanf(" %c", &serving_w_cream_1);

    printf("Ideal serving temperature (Celsius): ");
    scanf(" %lf", &ideal_temp_1); 
    printf("\n");
    // Input data for Coffee 2 :
    printf("COFFEE-2...\n");

    printf("Type ([L]ight,[B]lend): ");
    scanf(" %c", &type_2);

    printf("Grind size ([C]ourse,[F]ine): ");
    scanf(" %c", &grind_size_2);


    printf("Bag weight (g): ");
    scanf(" %d", &weight_g_2);

    printf("Best served with cream ([Y]es,[N]o): ");
    scanf(" %c", &serving_w_cream_2);

    printf("Ideal serving temperature (Celsius): ");
    scanf(" %lf", &ideal_temp_2); 
    printf("\n");
    // Input data for Coffee 3 :
    printf("COFFEE-3...\n");

    printf("Type ([L]ight,[B]lend): ");
    scanf(" %c", &type_3);

    printf("Grind size ([C]ourse,[F]ine): ");
    scanf(" %c", &grind_size_3);


    printf("Bag weight (g): ");
    scanf(" %d", &weight_g_3);

    printf("Best served with cream ([Y]es,[N]o): ");
    scanf(" %c", &serving_w_cream_3);

    printf("Ideal serving temperature (Celsius): ");
    scanf(" %lf", &ideal_temp_3);
    printf("\n");
    //Display table 
    printf("---+---------------+---------------+---------------+-------+--------------\n");
    printf("   |    Coffee     |    Coffee     |   Packaged    | Best  |   Serving\n");
    printf("   |     Type      |  Grind Size   |  Bag Weight   | Served| Temperature\n");
    printf("   +---------------+---------------+---------------+ With  +--------------\n");
    printf("ID | Light | Blend | Course | Fine |  (G) | Lbs    | Cream |   (C) |   (F)\n");
    printf("---+---------------+---------------+---------------+-------+--------------\n");
    printf(" 1 |   %d   |   %d   |    %d   |   %d  | %4d | %6.3lf |   %d   | %5.1lf | %5.1lf\n",(type_1 == 'l' || type_1 == 'L') , (type_1 == 'b' || type_1 == 'B') , (grind_size_1 == 'c' || grind_size_1 == 'C') , (grind_size_1 == 'f' || grind_size_1 == 'F') , weight_g_1, weight_g_1 / GRAMS_IN_LBS, (serving_w_cream_1=='y'||serving_w_cream_1=='Y') ,ideal_temp_1, 1.8 * ideal_temp_1 + 32);
    printf(" 2 |   %d   |   %d   |    %d   |   %d  | %4d | %6.3lf |   %d   | %5.1lf | %5.1lf\n", (type_2 == 'l' || type_2 == 'L') , (type_2 == 'b' || type_2 == 'B') , (grind_size_2 == 'c' || grind_size_2 == 'C'), (grind_size_2 == 'f' || grind_size_2 == 'F') , weight_g_2, weight_g_2 / GRAMS_IN_LBS, (serving_w_cream_2 == 'y' || serving_w_cream_2 == 'Y') , ideal_temp_2, 1.8 * ideal_temp_2 + 32);
    printf(" 3 |   %d   |   %d   |    %d   |   %d  | %4d | %6.3lf |   %d   | %5.1lf | %5.1lf\n", (type_3 == 'l' || type_3 == 'L') , (type_3 == 'b' || type_3 == 'B') , (grind_size_3 == 'c' || grind_size_3 == 'C') , (grind_size_3 == 'f' || grind_size_3 == 'F') , weight_g_3, weight_g_3 / GRAMS_IN_LBS, (serving_w_cream_3 == 'y' || serving_w_cream_3 == 'Y') , ideal_temp_3, 1.8 * ideal_temp_3 + 32);
    printf("\n");
    //Preference-1
    printf("Enter how you like your coffee and the coffee maker equipment you use...\n\n");
    printf("Coffee strength ([M]ild,[R]ich): "); 
    scanf(" %c", &coff_strength);
    printf("Do you like your coffee with cream ([Y]es,[N]o): ");
    scanf(" %c", &prefer_cream);
    printf("Typical number of daily servings: ");
    scanf(" %d", &daily_serv_num);
    printf("Maker ([R]esidential,[C]ommercial): ");
    scanf(" %c", &maker);
    printf("\n");
    //Display preference table-1 
     c1 = ((coff_strength == 'm' || coff_strength == 'M') && (type_1 == 'l' || type_1 == 'L')) || ((coff_strength == 'r' || coff_strength == 'R') && (type_1 == 'b' || type_1 == 'B'));
     m1 = ((maker == 'r' || maker == 'R') && (grind_size_1 == 'c' || grind_size_1 == 'C')) || ((maker == 'c' || maker == 'C') && (grind_size_1 == 'f' || grind_size_1 == 'F'));
     d1 = ((daily_serv_num >= 1 && daily_serv_num <= 4 && weight_g_1 == 250) || (daily_serv_num >= 5 && daily_serv_num <= 9 && weight_g_1 == 500) || (daily_serv_num >= 10 && weight_g_1 == 1000));
     p1 = ((prefer_cream == 'y' || prefer_cream == 'Y') && (serving_w_cream_1 == 'y' || serving_w_cream_1 == 'Y')) || ((prefer_cream == 'n' || prefer_cream == 'N') && (serving_w_cream_1 == 'n' || serving_w_cream_1 == 'N'));
     i1 = ((maker == 'r' || maker == 'R') && (ideal_temp_1 >= 60 && ideal_temp_1 <= 69.9)) || ((maker == 'c' || maker == 'C') && (ideal_temp_1 >= 70)); 
     
     c2 = ((coff_strength == 'm' || coff_strength == 'M') && (type_2 == 'l' || type_2 == 'L')) || ((coff_strength == 'r' || coff_strength == 'R') && (type_2 == 'b' || type_2 == 'B'));
     m2 = ((maker == 'r' || maker == 'R') && (grind_size_2 == 'c' || grind_size_2 == 'C')) || ((maker == 'c' || maker == 'C') && (grind_size_2 == 'f' || grind_size_2 == 'F'));
     d2 = ((daily_serv_num >= 1 && daily_serv_num <= 4 && weight_g_2 <= 250&&weight_g_2>0) || (daily_serv_num >= 5 && daily_serv_num <= 9 && weight_g_2 == 500) || (daily_serv_num >= 10 && weight_g_2 == 1000));
     p2 = ((prefer_cream == 'y' || prefer_cream == 'Y') && (serving_w_cream_2 == 'y' || serving_w_cream_2 == 'Y')) || ((prefer_cream == 'n' || prefer_cream == 'N') && (serving_w_cream_2 == 'n' || serving_w_cream_2 == 'N'));
     i2 =       ((maker == 'r' || maker == 'R') && (ideal_temp_2 >= 60 && ideal_temp_2 <= 69.9)) || ((maker == 'c' || maker == 'C') && (ideal_temp_2 >= 70));
   
     c3 = ((coff_strength == 'm' || coff_strength == 'M') && (type_3 == 'l' || type_3 == 'L')) || ((coff_strength == 'r' || coff_strength == 'R') && (type_3 == 'b' || type_3 == 'B'));
     m3 = ((maker == 'r' || maker == 'R') && (grind_size_3 == 'c' || grind_size_3 == 'C')) || ((maker == 'c' || maker == 'C') && (grind_size_3 == 'f' || grind_size_3 == 'F'));
     d3 = ((daily_serv_num >= 1 && daily_serv_num <= 4 && weight_g_3 <= 250 &&weight_g_3>0) || (daily_serv_num >= 5 && daily_serv_num <= 9 && weight_g_3 == 500) || (daily_serv_num >= 10 && weight_g_3 == 1000));
     p3 = ((prefer_cream == 'y' || prefer_cream == 'Y') && (serving_w_cream_3 == 'y' || serving_w_cream_3 == 'Y')) || ((prefer_cream == 'n' || prefer_cream == 'N') && (serving_w_cream_3 == 'n' || serving_w_cream_3 == 'N'));
     i3 =        ((maker == 'r' || maker == 'R') && (ideal_temp_3 >= 60 && ideal_temp_3 <= 69.9)) || ((maker == 'c' || maker == 'C') && (ideal_temp_3 >= 70));

    printf("The below table shows how your preferences align to the available products:\n\n");
    printf("--------------------+--------------------+-------------+-------+--------------\n");
    printf("  |     Coffee      |       Coffee       |  Packaged   | With  |   Serving\n");
    printf("ID|      Type       |     Grind Size     | Bag Weight  | Cream | Temperature\n");
    printf("--+-----------------+--------------------+-------------+-------+--------------\n");
    printf(" 1|       %d         |         %d          |      %d      |   %d   |      %d\n", c1, m1, d1, p1, i1);
    printf(" 2|       %d         |         %d          |      %d      |   %d   |      %d\n", c2, m2, d2, p2, i2);
    printf(" 3|       %d         |         %d          |      %d      |   %d   |      %d\n", c3, m3, d3, p3, i3);
    
    //Preference-2
    printf("\nEnter how you like your coffee and the coffee maker equipment you use...\n\n");
    printf("Coffee strength ([M]ild,[R]ich): ");
    scanf(" %c", &coff_strength);
    printf("Do you like your coffee with cream ([Y]es,[N]o): ");
    scanf(" %c", &prefer_cream);
    printf("Typical number of daily servings: ");
    scanf(" %d", &daily_serv_num);
    printf("Maker ([R]esidential,[C]ommercial): ");
    scanf(" %c", &maker);
    printf("\n");
    //Display preference table-2
    c1 = ((coff_strength == 'm' || coff_strength == 'M') && (type_1 == 'l' || type_1 == 'L')) || ((coff_strength == 'r' || coff_strength == 'R') && (type_1 == 'b' || type_1 == 'B'));
    m1 = ((maker == 'r' || maker == 'R') && (grind_size_1 == 'c' || grind_size_1 == 'C')) || ((maker == 'c' || maker == 'C') && (grind_size_1 == 'f' || grind_size_1 == 'F'));
    d1 = ((daily_serv_num >= 1 && daily_serv_num <= 4 && weight_g_1 == 250) || (daily_serv_num >= 5 && daily_serv_num <= 9 && weight_g_1 == 500) || (daily_serv_num >= 10 && weight_g_1 == 1000));
    p1 = ((prefer_cream == 'y' || prefer_cream == 'Y') && (serving_w_cream_1 == 'y' || serving_w_cream_1 == 'Y')) || ((prefer_cream == 'n' || prefer_cream == 'N') && (serving_w_cream_1 == 'n' || serving_w_cream_1 == 'N'));
    i1 = ((maker == 'r' || maker == 'R') && (ideal_temp_1 >= 60 && ideal_temp_1 <= 69.9)) || ((maker == 'c' || maker == 'C') && (ideal_temp_1 >= 70));

    c2 = ((coff_strength == 'm' || coff_strength == 'M') && (type_2 == 'l' || type_2 == 'L')) || ((coff_strength == 'r' || coff_strength == 'R') && (type_2 == 'b' || type_2 == 'B'));
    m2 = ((maker == 'r' || maker == 'R') && (grind_size_2 == 'c' || grind_size_2 == 'C')) || ((maker == 'c' || maker == 'C') && (grind_size_2 == 'f' || grind_size_2 == 'F'));
    d2 = ((daily_serv_num >= 1 && daily_serv_num <= 4 && weight_g_2 == 250) || (daily_serv_num >= 5 && daily_serv_num <= 9 && weight_g_2 == 500) || (daily_serv_num >= 10 && weight_g_2 == 1000));
    p2 = ((prefer_cream == 'y' || prefer_cream == 'Y') && (serving_w_cream_2 == 'y' || serving_w_cream_2 == 'Y')) || ((prefer_cream == 'n' || prefer_cream == 'N') && (serving_w_cream_2 == 'n' || serving_w_cream_2 == 'N'));
    i2 = ((maker == 'r' || maker == 'R') && (ideal_temp_2 >= 60 && ideal_temp_2 <= 69.9)) || ((maker == 'c' || maker == 'C') && (ideal_temp_2 >= 70));

    c3 = ((coff_strength == 'm' || coff_strength == 'M') && (type_3 == 'l' || type_3 == 'L')) || ((coff_strength == 'r' || coff_strength == 'R') && (type_3 == 'b' || type_3 == 'B'));
    m3 = ((maker == 'r' || maker == 'R') && (grind_size_3 == 'c' || grind_size_3 == 'C')) || ((maker == 'c' || maker == 'C') && (grind_size_3 == 'f' || grind_size_3 == 'F'));
    d3 = ((daily_serv_num >= 1 && daily_serv_num <= 4 && weight_g_3 == 250) || (daily_serv_num >= 5 && daily_serv_num <= 9 && weight_g_3 == 500) || (daily_serv_num >= 10 && weight_g_3 == 1000));
    p3 = ((prefer_cream == 'y' || prefer_cream == 'Y') && (serving_w_cream_3 == 'y' || serving_w_cream_3 == 'Y')) || ((prefer_cream == 'n' || prefer_cream == 'N') && (serving_w_cream_3 == 'n' || serving_w_cream_3 == 'N'));
    i3 = ((maker == 'r' || maker == 'R') && (ideal_temp_3 >= 60 && ideal_temp_3 <= 69.9)) || ((maker == 'c' || maker == 'C') && (ideal_temp_3 >= 70));

    printf("The below table shows how your preferences align to the available products:\n\n");
    printf("--------------------+--------------------+-------------+-------+--------------\n");
    printf("  |     Coffee      |       Coffee       |  Packaged   | With  |   Serving\n");
    printf("ID|      Type       |     Grind Size     | Bag Weight  | Cream | Temperature\n");
    printf("--+-----------------+--------------------+-------------+-------+--------------\n");
    printf(" 1|       %d         |         %d          |      %d      |   %d   |      %d\n", c1, m1, d1, p1, i1);
    printf(" 2|       %d         |         %d          |      %d      |   %d   |      %d\n", c2, m2, d2, p2, i2);
    printf(" 3|       %d         |         %d          |      %d      |   %d   |      %d\n", c3, m3, d3, p3, i3);
    
    printf("\nHope you found a product that suits your likes!\n");




    return 0;
}
