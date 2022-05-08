/*
*****************************************************************************
                          Workshop - #4 (P1)
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
    char loop_type;
    int times;
    int quit ;
    
    printf("+----------------------+\n");
    printf("Loop application STARTED\n");
    printf("+----------------------+\n\n");
    do 
    {
        quit = 0;
        printf("D = do/while | W = while | F = for | Q = quit\n");
        printf("Enter loop type and the number of times to iterate (Quit=Q0): ");
        scanf(" %c%d",&loop_type,&times);
        int valid_times = times >= 3 && times <=20;
        int valid_type = loop_type == 'D' || loop_type == 'W' || loop_type == 'F';
        if (loop_type == 'Q' && times == 0)
        {
            quit = 1;

        }
        else if (loop_type == 'Q' && times != 0)
        {
            printf("ERROR: To quit, the number of iterations should be 0!\n\n");
            quit = 0;
        }
        else if (!valid_type)
        {
            printf("ERROR: Invalid entered value(s)!\n\n");
        }
        else if (!valid_times)
        {
            printf("ERROR: The number of iterations must be between 3-20 inclusive!\n\n");
            quit = 0;
        }
        
        else if (loop_type =='D'&& valid_times)
        {
            int i ;
            printf("DO-WHILE: ");
            for (i=0;i<times;i++)
            {
                printf("D");
            }
            printf("\n\n");
        }
        else if (loop_type == 'W' && valid_times)
        {
            int i;
            printf("WHILE   : ");
            for (i = 0;i < times;i++)
            {
                printf("W");
            }
            printf("\n\n");
        }
        else if (loop_type == 'F' && valid_times)
        {
            int i;
            printf("FOR     : ");
            for (i = 0;i < times;i++)
            {
                printf("F");
            }
            printf("\n\n");
        }
        else if (!valid_type)
            {
            printf("ERROR: Invalid entered value(s)!\n\n");
            } 
        
        

    } while (quit ==0);
    printf("\n");
    printf("+--------------------+\n");
    printf("Loop application ENDED\n");
    printf("+--------------------+\n");
    return 0;
}