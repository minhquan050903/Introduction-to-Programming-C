/*
*****************************************************************************
						  Workshop - #6 (P2)
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
#define MIN_ITEMS 1
#define MAX_ITEMS 10
#define MIN_PRIORITY 1
#define MAX_PRIORITY 3
int main(void)
{
	int months, years, remainingMonths, months_1, years_1, remainingMonths_1, months_2, years_2, remainingMonths_2, months_3, years_3, remainingMonths_3;
	double totalCost = 0, priorityCosts_1 = 0, priorityCosts_2 = 0, priorityCosts_3 = 0;;
	double inputNet;
	const double minCost = 100.00;
	const double maxNet = 400000.00;
	const double minNet = 500.00;
	int items, i, select, valid, valid1, valid2, priorityChoice;
	double costs[10];
	int priority[10];
	char option[10];
	printf("+--------------------------+\n");
	printf("+   Wish List Forecaster   |\n");
	printf("+--------------------------+\n\n");
	do
	{

		printf("Enter your monthly NET income: $");
		scanf("%lf", &inputNet);
		if (inputNet < minNet)
		{
			printf("ERROR: You must have a consistent monthly income of at least $%.2lf\n\n", minNet);

		}
		else if (inputNet > maxNet)
		{
			printf("ERROR: Liar! I'll believe you if you enter a value no more than $%.2lf\n\n", maxNet);

		}

	} while (inputNet<minNet || inputNet>maxNet);
	do
	{

		printf("\nHow many wish list items do you want to forecast?: ");
		scanf("%d", &items);
		if (items <= MIN_ITEMS || items >= MAX_ITEMS)
		{
			printf("ERROR: List is restricted to between %d and %d items.\n", MIN_ITEMS, MAX_ITEMS);

		}

	} while (items <= MIN_ITEMS || items >= MAX_ITEMS);
	for (i = 0; i < items;i++)
	{

		printf("\nItem-%d Details:", i + 1);
		do
		{
			printf("\n   Item cost: $");
			scanf("%lf", &costs[i]);
			if (costs[i] <= minCost)

				printf("      ERROR: Cost must be at least $%.2lf", minCost);

		} while (costs[i] < minCost);
		do
		{
			printf("   How important is it to you? [1=must have, 2=important, 3=want]: ");
			scanf("%d", &priority[i]);
			if (priority[i] < 1 || priority[i]>3)
			{
				printf("      ERROR: Value must be between 1 and 3\n");
			}
		} while (priority[i] < 1 || priority[i]>3);
		do
		{
			printf("   Does this item have financing options? [y/n]: ");
			scanf(" %c", &option[i]);
			if (option[i] != 'y' && option[i] != 'n')
				printf("      ERROR: Must be a lowercase 'y' or 'n'\n");
		} while (option[i] != 'y' && option[i] != 'n');
	}
	printf("\nItem Priority Financed        Cost");
	printf("\n---- -------- -------- -----------\n");
	for (i = 0; i < items;i++)
	{
		printf("%3d  %5d    %5c    %11.2lf\n", i + 1, priority[i], option[i], costs[i]);
		totalCost += costs[i];
	}
	printf("---- -------- -------- -----------\n");
	printf("                      $%11.2lf\n\n", totalCost);
	do {
		valid1 = 1;
		printf("How do you want to forecast your wish list?\n");
		printf(" 1. All items (no filter)\n 2. By priority\n 0. Quit/Exit\nSelection: ");
		scanf("%d", &select);
		switch (select)
		{
		case 1:

			valid = 0;
			months = (int)(totalCost / inputNet);
			years = months / 12;
			remainingMonths = (months % 12) + 1;
			printf("\n====================================================\n");
			printf("Filter:   All items\n");
			printf("Amount:   $%.2lf\n", totalCost);
			printf("Forecast: %d years, %d months\n", years, remainingMonths);
			for (i = 0; i < items; i++)
			{
				if (option[i] == 'y')
				{
					valid = 1;
				}
			}
			if (valid == 1)
			{
				printf("NOTE: Financing options are available on some items.\n");
				printf("      You can likely reduce the estimated months.\n");

			}

			printf("====================================================\n\n");
			break;
		case 2:
			do
			{
				valid2 = 1;
				printf("\nWhat priority do you want to filter by? [1-3]: ");
				scanf("%d", &priorityChoice);
				printf("\n");

				if (priorityChoice< MIN_PRIORITY || priorityChoice> MAX_PRIORITY)
				{
					printf("ERROR: Value must be between 1 and 3\n");

				}
				else
				{
					valid2 = 0;
				}


				if (priorityChoice == 1)
				{
					for (i = 0; i < items; i++)
					{
						if (priority[i] == 1)
						{
							priorityCosts_1 += costs[i];
						}
					}
					months_1 = (int)(priorityCosts_1 / inputNet);
					years_1 = months_1 / 12;
					remainingMonths_1 = (months_1 % 12) + 1;
					printf("====================================================\n");
					printf("Filter:   by priority (%d)\n", priorityChoice);
					printf("Amount:   $%1.2lf\n", priorityCosts_1);
					printf("Forecast: %d years, %d months\n", years_1, remainingMonths_1);

					for (i = 0; i <= items; i++)
					{
						if (priority[i] == 1)
						{
							if (option[i] == 'y')
							{
								printf("NOTE: Financing options are available on some items.\n");
								printf("      You can likely reduce the estimated months.\n");
							}
						}
					}
					printf("====================================================\n\n");
				}
				if (priorityChoice == 2)
				{
					for (i = 0; i < items; i++)
					{
						if (priority[i] == 2)
						{
							priorityCosts_2 += costs[i];
						}
					}
					months_2 = (int)(priorityCosts_2 / inputNet);
					years_2 = months_2 / 12;
					remainingMonths_2 = (months_2 % 12) + 1;
					printf("====================================================\n");
					printf("Filter:   by priority (%d)\n", priorityChoice);
					printf("Amount:   $%1.2lf\n", priorityCosts_2);
					printf("Forecast: %d years, %d months\n", years_2, remainingMonths_2);

					for (i = 0; i <= items; i++)
					{
						if (priority[i] == 2)
						{
							if (option[i] == 'y')
							{
								printf("NOTE: Financing options are available on some items.\n");
								printf("      You can likely reduce the estimated months.\n");
							}
						}
					}

					printf("====================================================\n\n");
				}
				if (priorityChoice == 3)
				{
					for (i = 0; i < items; i++)
					{
						if (priority[i] == 3)
						{
							priorityCosts_3 += costs[i];
						}
					}
					months_3 = (int)(priorityCosts_3 / inputNet);
					years_3 = months_3 / 12;
					remainingMonths_3 = (months_3 % 12) + 1;
					printf("====================================================\n");
					printf("Filter:   by priority (%d)\n", priorityChoice);
					printf("Amount:   $%1.2lf\n", priorityCosts_3);
					printf("Forecast: %d years, %d months\n", years_3, remainingMonths_3);

					for (i = 0; i <= items; i++)
					{
						if (priority[i] == 3)
						{
							if (option[i] == 'y')
							{
								printf("NOTE: Financing options are available on some items.\n");
								printf("      You can likely reduce the estimated months.\n");
							}
						}
					}
					printf("====================================================\n\n");
				}

			} while (valid2 != 0);
			break;


		case 0:

			printf("\nBest of luck in all your future endeavours!");
			valid1 = 0;
			break;
		default:

			printf("\nERROR: Invalid menu selection.\n\n");

			break;
		}


	} while (valid1 != 0);
	printf("\n");
	return 0;
}
