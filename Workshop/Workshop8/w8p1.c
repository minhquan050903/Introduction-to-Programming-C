/*
*****************************************************************************
                          Workshop - #8 (P1)
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




// System Libraries
#include <stdio.h>

// User Libraries

#include "w8p1.h"
// 1. Get user input of int type and validate for a positive non-zero number
//    (return the number while also assigning it to the pointer argument)
int getIntPositive(int* int_num)
{
	int i;
	int integer_number = 0;
	for (i = 0; i < MAXIMUM_PRODUCT; i++)
	{
		scanf(" %d", &integer_number);
		if (int_num != NULL && integer_number > 0)
		{
			*int_num = integer_number;
			return integer_number;

		}

		else if (integer_number <= 0)
		{
			printf("ERROR: Enter a positive value: ");
		}
		else
		{
			return integer_number;
		}
	}
	return 0;
}



// 2. Get user input of double type and validate for a positive non-zero number
//    (return the number while also assigning it to the pointer argument)
double getDoublePositive(double* dbl_num)
{
	int i;
	double double_number = 0.0;
	for (i = 0; i < MAXIMUM_PRODUCT; i++)
	{
		scanf(" %lf", &double_number);
		if (dbl_num != NULL && double_number > 0)
		{
			*dbl_num = double_number;
			return double_number;

		}

		else if (double_number <= 0)
		{
			printf("ERROR: Enter a positive value: ");
		}
		else
		{
			return double_number;
		}
	}
	return 0;
}


// 3. Opening Message (include the number of products that need entering)
void openingMessage(const int require_products)
{

	printf("Cat Food Cost Analysis\n");
	printf("======================\n\n");
	printf("Enter the details for %d dry food bags of product data for analysis.\n", require_products);
	printf("NOTE: A 'serving' is %dg\n", TOTAL_GRAMS);
}


// 4. Get user input for the details of cat food product
double getCatFoodInfo(int* sku, double* rate, double* weight, int* cal, const int sequence)
{
	printf("\n");
	printf("Cat Food Product #%d\n", sequence);
	printf("--------------------\n");
	printf("SKU           : ");
	*sku = getIntPositive(NULL);
	printf("PRICE         : $");
	*rate = getDoublePositive(NULL);
	printf("WEIGHT (LBS)  : ");
	*weight = getDoublePositive(NULL);
	printf("CALORIES/SERV.: ");
	*cal = getIntPositive(NULL);
	return 0;
}

// 5. Display the formatted table header
void displayCatFoodHeader(void)
{
	printf("SKU         $Price    Bag-lbs Cal/Serv\n");
	printf("------- ---------- ---------- --------\n");


}

// 6. Display a formatted record of cat food data
void displayCatFoodData(const int sku, const double* rate, const double* weight, const int cal)
{
	printf("%07d %10.2lf %10.1lf %8d\n", sku, *rate, *weight, cal);


}


// 7. Logic entry point
void start(void)
{
	int i;
	struct CatFoodInfo catFoodData[MAXIMUM_PRODUCT] = { { 0 } };
	openingMessage(MAXIMUM_PRODUCT);
	for (i = 0; i < MAXIMUM_PRODUCT; i++)
	{
		getCatFoodInfo(&catFoodData[i].sku, &catFoodData[i].product_price, &catFoodData[i].weight, &catFoodData[i].calories, i + 1);
	}
	printf("\n");
	displayCatFoodHeader();
	for (i = 0; i < MAXIMUM_PRODUCT; i++)
	{
		displayCatFoodData(catFoodData[i].sku, &catFoodData[i].product_price, &catFoodData[i].weight, catFoodData[i].calories);
	}
}