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
#define LOG_DAYS 3;
int main(void)
{
	const int jan = 1, dec = 12;
	int inputYear = 0, inputMonth = 0;
    int valid,d;
    double morning_rate, sum_morning_rate = 0, evening_rate, sum_evening_rate = 0, final_sum, average_morning, average_evening, final_average;

	printf("General Well-being Log\n");
	printf("======================\n");

	while (inputYear < MIN_YEAR || inputYear>MAX_YEAR || inputMonth < jan || inputMonth>dec)
	{
		printf("Set the year and month for the well-being log (YYYY MM): ");
		scanf("%d %d", &inputYear, &inputMonth);
		if (inputYear < MIN_YEAR || inputYear>MAX_YEAR)
		{
			printf("   ERROR: The year must be between %d and %d inclusive\n", MIN_YEAR, MAX_YEAR);

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
    for (d = 1; d <= LOG_DAYS d++)
    {
        switch (inputMonth)
        {
        case 1:
            printf("\n%d-JAN-%02d\n", inputYear, d);
            break;
        case 2:
            printf("\n%d-FEB-%02d\n", inputYear, d);
            break;
        case 3:
            printf("\n%d-MAR-%02d\n", inputYear, d);
            break;
        case 4:
            printf("\n%d-APR-%02d\n", inputYear, d);
            break;
        case 5:
            printf("\n%d-MAY-%02d\n", inputYear, d);
            break;
        case 6:
            printf("\n%d-JUN-%02d\n", inputYear, d);
            break;
        case 7:
            printf("\n%d-JUL-%02d\n", inputYear, d);
            break;
        case 8:
            printf("\n%d-AUG-%02d\n", inputYear, d);
            break;
        case 9:
            printf("\n%d-SEP-%02d\n", inputYear, d);
            break;
        case 10:
            printf("\n%d-OCT-%02d\n", inputYear, d);
            break;
        case 11:
            printf("\n%d-NOV-%02d\n", inputYear, d);
            break;
        case 12:
            printf("\n%d-DEC-%02d\n", inputYear, d);
            break;
        }
        do {
            valid = 1;
            printf("   Morning rating (0.0-5.0): ");
            scanf(" %lf", &morning_rate);

            if (morning_rate < 0.00 || morning_rate > 5.00)
            {
                printf("      ERROR: Rating must be between 0.0 and 5.0 inclusive!\n");
                valid = 0;
            }
            else
                sum_morning_rate += morning_rate;



        } while (!valid);
        do {
            valid = 1;
            printf("   Evening rating (0.0-5.0): ");
            scanf("%lf", &evening_rate);

            if (evening_rate < 0.00 || evening_rate > 5.00)
            {
                printf("      ERROR: Rating must be between 0.0 and 5.0 inclusive!\n");
                valid = 0;
            }
            else
            {
                sum_evening_rate += evening_rate;
            }



        } while (!valid);
    }
    average_morning = sum_morning_rate / LOG_DAYS;
    average_evening = sum_evening_rate / LOG_DAYS;
    final_sum = sum_evening_rate + sum_morning_rate;
    final_average = (average_evening + average_morning) / 2;
    printf("\nSummary\n");
    printf("=======\n");
    printf("Morning total rating: %.3lf\n", sum_morning_rate);
    printf("Evening total rating:  %.3lf\n", sum_evening_rate);
    printf("----------------------------\n");
    printf("Overall total rating: %.3lf\n", final_sum);
    printf("\nAverage morning rating:  %.1lf\n", average_morning);
    printf("Average evening rating:  %.1lf\n", average_evening);
    printf("----------------------------\n");
    printf("Average overall rating:  %.1lf\n", final_average);
    return 0;
}