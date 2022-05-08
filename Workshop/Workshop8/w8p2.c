/*
*****************************************************************************
                          Workshop - #8 (P2)
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

#include "w8p2.h"
// ----------------------------------------------------------------------------
// PART-1

// 1. Get user input of int type and validate for a positive non-zero number
//    (return the number while also assigning it to the pointer argument)
int getIntPositive(int* int_num)
{
	int integer_number = 0;
	do
	{
		scanf("%d", &integer_number);
		if (integer_number < 1)
		{
			printf("ERROR: Enter a positive value: ");
		}
	} while (integer_number < 1);
	if (int_num != NULL)
	{
		*int_num = integer_number;
	}
	return(integer_number);
}





// 2. Get user input of double type and validate for a positive non-zero number
//    (return the number while also assigning it to the pointer argument)
double getDoublePositive(double* dbl_num)
{
	double double_number = 0.0;
	while (double_number < 1.0)
	{
		scanf("%lf", &double_number);
		if (double_number < 1)
		{
			printf("ERROR: Enter a positive value: ");
		}
	}
	if (dbl_num != NULL)
	{
		*dbl_num = double_number;
	}
	return double_number;
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
struct CatFoodInfo getCatFoodInfo(const int i)
{
	double price, weight;
	int cal, sku;
	struct CatFoodInfo data = { 0 };
	printf("\n");
	printf("Cat Food Product #%d\n", i + 1);
	printf("--------------------\n");
	printf("SKU           : ");
	data.sku = getIntPositive(&sku);
	printf("PRICE         : $");
	data.product_price = getDoublePositive(&price);
	printf("WEIGHT (LBS)  : ");
	data.weight_in_lbs = getDoublePositive(&weight);
	printf("CALORIES/SERV.: ");
	data.calories = getIntPositive(&cal);
	return data;
}

// 5. Display the formatted table header
void displayCatFoodHeader(void)
{
	printf("\nSKU         $Price    Bag-lbs Cal/Serv\n");
	printf("------- ---------- ---------- --------\n");


}

// 6. Display a formatted record of cat food data
void displayCatFoodData(const int sku, const double rate, const double weight, const int cal)
{
	printf("%07d %10.2lf %10.1lf %8d\n", sku, rate, weight, cal);


}


// 7. Logic entry point
void start(void)
{
	struct CatFoodInfo catFoodDetail[MAXIMUM_PRODUCT];
	int i = 0, cheap_product = 0;
	openingMessage(MAXIMUM_PRODUCT);
	for (i = 0; i < MAXIMUM_PRODUCT; i++)
	{
		catFoodDetail[i] = getCatFoodInfo(i);
	}
	displayCatFoodHeader();
	for (i = 0; i < MAXIMUM_PRODUCT; i++)
	{
		displayCatFoodData(catFoodDetail[i].sku, catFoodDetail[i].product_price, catFoodDetail[i].weight_in_lbs, catFoodDetail[i].calories);
	}
	struct ReportData report[MAXIMUM_PRODUCT];
	displayReportHeader();
	for (i = 0; i < MAXIMUM_PRODUCT; i++)
	{
		report[i] = calculateReportData(catFoodDetail[i]);
		if (report[i].perServe < report[i - 1].perServe)
		{
			cheap_product = i;
		}
	}
	int j;
	for (j = 0; j < MAXIMUM_PRODUCT; j++)
	{
		struct ReportData x = { 0 };
		x = report[j];
		displayReportData(x, cheap_product);
		if (cheap_product == j)
		{
			printf(" ***");
		}
		printf("\n");
	}
	displayFinalAnalysis(catFoodDetail[cheap_product]);
}



// ----------------------------------------------------------------------------
// PART-2

// 8. convert lbs: kg (divide by 2.20462)
double convertLbsKg(const double* lbs, double* kg)
{
	double convert;
	convert = *lbs / KG_IN_LBS;
	if (kg != NULL)
	{
		*kg = convert;
	}
	return convert;
}


// 9. convert lbs: g (call convertKG, then * 1000)
int convertLbsG(const double* lbs, int* g)
{
	int i;
	i = convertLbsKg(lbs, 0) * 1000;
	if (g != NULL)
	{
		*g = i;
	}
	return i;
}

// 10. convert lbs: kg and g
void convertLbs(const double* lbs_convert, double* kg, int* g)
{
	convertLbsKg(lbs_convert, kg);
	convertLbsG(lbs_convert, g);
}

// 11. calculate: servings based on gPerServ
double calculateServings(const int volume, const int sum, double* result)
{
	double i;
	i = (double)sum / (double)volume;
	if (result != NULL)
	{
		*result = i;
	}
	return(i);
}

// 12. calculate: cost per serving
double calculateCostPerServing(const double* rate, const double* result, double* CostofResult)
{
	double cost = 0;
	cost = *rate / *result;
	if (CostofResult != NULL) {
		*CostofResult = cost;
	}
	return(cost);
}


// 13. calculate: cost per calorie
double calculateCostPerCal(const double* price, const double* calories, double* CostCalories)
{
	double cost = 0;
	cost = *price / *calories;
	if (CostCalories != NULL) {
		*CostCalories = cost;
	}
	return(cost);
}

// 14. Derive a reporting detail record based on the cat food product data
struct ReportData calculateReportData(const struct CatFoodInfo getDetailCatFood)
{
	struct ReportData reportinfo;
	double cal;
	// For SKU, RATE, Weight and Calories
	reportinfo.sku = getDetailCatFood.sku;
	reportinfo.price = getDetailCatFood.product_price;
	reportinfo.lbs = getDetailCatFood.weight_in_lbs;
	reportinfo.calories = getDetailCatFood.calories;
	// For kg and g
	reportinfo.kg = convertLbsKg(&getDetailCatFood.weight_in_lbs, &reportinfo.kg);
	reportinfo.g = convertLbsG(&getDetailCatFood.weight_in_lbs, &reportinfo.g);
	reportinfo.sumServe = calculateServings(TOTAL_GRAMS, reportinfo.g, &reportinfo.sumServe);
	reportinfo.perServe = calculateCostPerServing(&reportinfo.price, &reportinfo.sumServe, &reportinfo.perServe);
	cal = reportinfo.calories * reportinfo.sumServe;
	reportinfo.calPerServe = calculateCostPerCal(&reportinfo.price, &cal, &reportinfo.calPerServe);
	return(reportinfo);
}

// 15. Display the formatted table header for the analysis results
void displayReportHeader(void)
{
	printf("\nAnalysis Report (Note: Serving = %dg)\n", TOTAL_GRAMS);
	printf("---------------\n");
	printf("SKU         $Price    Bag-lbs     Bag-kg     Bag-g Cal/Serv Servings  $/Serv   $/Cal\n");
	printf("------- ---------- ---------- ---------- --------- -------- -------- ------- -------\n");
}

// 16. Display the formatted data row in the analysis table
void displayReportData(const struct ReportData reportinfo, const int cheap)

{
	printf("%07d %10.2lf %10.1lf %10.4lf %9d %8d %8.1lf %7.2lf %7.5lf", reportinfo.sku, reportinfo.price, reportinfo.lbs, reportinfo.kg, reportinfo.g, reportinfo.calories, reportinfo.sumServe, reportinfo.perServe, reportinfo.calPerServe);
}

// 17. Display the findings (cheapest)
void displayFinalAnalysis(const struct CatFoodInfo cheaper_product)
{
	printf("\n");
	printf("Final Analysis\n--------------\n");
	printf("Based on the comparison data, the PURRR-fect economical option is:\n");
	printf("SKU:%07d Price: $%.2lf\n\n", cheaper_product.sku, cheaper_product.product_price);
	printf("Happy shopping!\n");
}

// ----------------------------------------------------------------------------

// 7. Logic entry point

