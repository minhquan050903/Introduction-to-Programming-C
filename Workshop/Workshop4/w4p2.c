/*
*****************************************************************************
                          Workshop - #4 (P2)
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
    int flag_1, flag_2, flag_3, flag_4,flag_5, flag_6, flag_7, flag_8, flag_9, flag_10;
    int numApp, numOra, numTom, numPea,numCab;
    int pickApp, pickOra, pickTom, pickPea, pickCab;
    int choice;
    int remainApp, remainOra, remainTom, remainPea, remainCab;
    

    
    do {
        choice = 1;
        printf("Grocery Shopping\n");
        printf("================\n");
        //Apple
        do
        {
            flag_1 = 0;
            printf("How many APPLES do you need? : ");
            scanf(" %d", &numApp);
            if (numApp < 0)
            {
                printf("ERROR: Value must be 0 or more.\n");
            }
            else
                flag_1 = 1;
        } while (flag_1 == 0);
        printf("\n");
        //Oranges :
        do
        {
            flag_2 = 0;
            printf("How many ORANGES do you need? : ");
            scanf(" %d", &numOra);
            if (numOra < 0)
            {
                printf("ERROR: Value must be 0 or more.\n");
            }
            else
                flag_2 = 1;
        } while (flag_2 == 0);
        printf("\n");
        //Pears
        do
        {
            flag_3 = 0;
            printf("How many PEARS do you need? : ");
            scanf(" %d", &numPea);
            if (numPea < 0)
            {
                printf("ERROR: Value must be 0 or more.\n");
            }
            else
                flag_3 = 1;
        } while (flag_3 == 0);
        printf("\n");
        //Tomatoes
        do
        {
            flag_4 = 0;
            printf("How many TOMATOES do you need? : ");
            scanf(" %d", &numTom);
            if (numTom < 0)
            {
                printf("ERROR: Value must be 0 or more.\n");
            }
            else
                flag_4 = 1;
        } while (flag_4 == 0);
        printf("\n");
        //Cabbages
        do
        {
            flag_5 = 0;
            printf("How many CABBAGES do you need? : ");
            scanf(" %d", &numCab);
            if (numCab < 0)
            {
                printf("ERROR: Value must be 0 or more.\n");
            }
            else
                flag_5 = 1;
        } while (flag_5 == 0);
        printf("\n");
        printf("--------------------------\n");
        printf("Time to pick the products!\n");
        printf("--------------------------\n\n");

        if (numApp > 0) {
            flag_6 = 0;
            remainApp = numApp;
            do {
                printf("Pick some APPLES... how many did you pick? : ");
                scanf(" %d", &pickApp);
                if (pickApp < 1)
                {
                    printf("ERROR: You must pick at least 1!\n");
                }
                else if (pickApp > remainApp)
                {
                    printf("You picked too many... only %d more APPLE(S) are needed.\n", remainApp);
                }
                else
                {
                    remainApp -= pickApp;
                    if (remainApp == 0)
                    {
                        printf("Great, that's the apples done!\n\n");
                        flag_6 = 1;
                    }
                    else
                    {
                        printf("Looks like we still need some APPLES...\n");
                    }
                }
            } while (flag_6 == 0);
        }
        
        if (numOra > 0) {
            flag_8 = 0;
            remainOra = numOra;
            do {
                printf("Pick some ORANGES... how many did you pick? : ");
                scanf(" %d", &pickOra);
                if (pickOra < 1)
                {
                    printf("ERROR: You must pick at least 1!\n");
                }
                else if (pickOra > remainOra)
                {
                    printf("You picked too many... only %d more ORANGE(S) are needed.\n", remainOra);
                }
                else
                {
                    remainOra -= pickOra;
                    if (remainOra == 0)
                    {
                        printf("Great, that's the oranges done!\n\n");
                        flag_8 = 1;
                    }
                    else
                    {
                        printf("Looks like we still need some ORANGES...\n");
                    }
                }
            } while (flag_8 == 0);
        }
        
        if (numPea > 0) {
            flag_7 = 0;
            remainPea = numPea;
            do {
                printf("Pick some PEARS... how many did you pick? : ");
                scanf(" %d", &pickPea);
                if (pickPea < 1)
                {
                    printf("ERROR: You must pick at least 1!\n");
                }
                else if (pickPea > remainPea)
                {
                    printf("You picked too many... only %d more PEAR(S) are needed.\n", remainPea);
                }
                else
                {
                    remainPea -= pickPea;
                    if (remainPea == 0)
                    {
                        printf("Great, that's the pears done!\n\n");
                        flag_7 = 1;
                    }
                    else
                    {
                        printf("Looks like we still need some PEARS...\n");
                    }
                }
            } while (flag_7 == 0);
        }
       
        if (numTom > 0) {
            flag_9 = 0;
            remainTom = numTom;
            do {
                printf("Pick some TOMATOES... how many did you pick? : ");
                scanf(" %d", &pickTom);
                if (pickTom < 1)
                {
                    printf("ERROR: You must pick at least 1!\n");
                }
                else if (pickTom > remainTom)
                {
                    printf("You picked too many... only %d more TOMATO(ES) are needed.\n", remainTom);
                }
                else
                {
                    remainTom -= pickTom;
                    if (remainTom == 0)
                    {
                        printf("Great, that's the tomatoes done!\n");
                        flag_9 = 1;
                    }
                    else
                    {
                        printf("Looks like we still need some TOMATOES...\n");
                    }
                }
            } while (flag_9 == 0);
        }
        
        if (numCab > 0) {
            flag_10 = 0;
            remainCab = numCab;
            do {
                printf("Pick some CABBAGES... how many did you pick? : ");
                scanf(" %d", &pickCab);
                if (pickCab < 1)
                {
                    printf("ERROR: You must pick at least 1!\n");
                }
                else if (pickCab > remainCab)
                {
                    printf("You picked too many... only %d more CABBAGE(S) are needed.\n", remainCab);
                }
                else
                {
                    remainCab -= pickCab;
                    if (remainCab == 0)
                    {
                        printf("Great, that's the cabbages done!\n");
                        flag_10 = 1;
                    }
                    else
                    {
                        printf("Looks like we still need some CABBAGES...\n");
                    }
                }
            } while (flag_10 == 0);
        }
        printf("\n");
        printf("All the items are picked!\n\n");
        printf("Do another shopping? (0=NO): ");
        scanf(" %d", &choice);
        printf("\n");
    }while (choice != 0); 
    printf("Your tasks are done for today - enjoy your free time!\n");

    return 0;
}