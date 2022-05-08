/*
*****************************************************************************
						  Workshop - #5 (P1)
Full Name  : Tran Minh Quan Nguyen
Student ID#: 116796210
Email      : nguyen-tran-minh-qua@myseneca.ca
Section    : IPC144NRR

Authenticity declaration:
I declare this submission is the result of my own work and has not been
shared with any other student or 3rd party content provider. This submitted
piece of work is entirely of my own creation.
*****************************************************************************
*/

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#define MIN_YEAR 2012
#define MAX_YEAR 2022
int main(void)
{
	const int jan = 1, dec = 12;
	int inputYear = 0, inputMonth = 0;

	printf("General Well-being Log\n");
	printf("======================\n");

	while (inputYear < MIN_YEAR || inputYear>MAX_YEAR || inputMonth < jan || inputMonth>dec)
	{
		printf("Set the year and month for the well-being log (YYYY MM): ");
		scanf("%d %d", &inputYear, &inputMonth);
		if (inputYear < MIN_YEAR || inputYear>MAX_YEAR)
		{
			printf("   ERROR: The year must be between %d and %d inclusive\n",MIN_YEAR,MAX_YEAR);

		}
		if (inputMonth < jan || inputMonth>dec)
		{
			printf("   ERROR: Jan.(1) - Dec.(12)\n");
		}
		if (inputYear >= MIN_YEAR && inputYear <= MAX_YEAR && inputMonth >= jan && inputMonth <= dec)
		{
			printf("\n*** Log date set! ***\n");
			
		}
	}
	switch (inputMonth)
	{
	case 1:
	{
		printf("\nLog starting date: %d-JAN-01", inputYear);
		break;
	}
	case  2:
	{
		printf("\nLog starting date: %d-FEB-01", inputYear);
		break;
	}
	case  3:
	{
		printf("\nLog starting date: %d-MAR-01", inputYear);
		break;

	}
	case  4:
	{
		printf("\nLog starting date: %d-APR-01", inputYear);
		break;

	}
	case  5:
	{
		printf("\nLog starting date: %d-MAY-01", inputYear);
		break;

	}
	case  6:
	{
		printf("\nLog starting date: %d-JUN-01", inputYear);
		break;

	}
	case  7:
	{
		printf("\nLog starting date: %d-JUL-01", inputYear);
		break;

	}
	case  8:
	{
		printf("\nLog starting date: %d-AUG-01", inputYear);
		break;

	}
	case  9:
	{
		printf("\nLog starting date: %d-SEP-01", inputYear);
		break;

	}
	case  10:
	{
		printf("\nLog starting date: %d-OCT-01", inputYear);
		break;

	}
	case  11:
	{
		printf("\nLog starting date: %d-NOV-01", inputYear);
		break;

	}
	case  12:
	{
		printf("\nLog starting date: %d-DEC-01", inputYear);
		break;

	}
	}
	printf("\n");
	return 0;
}
