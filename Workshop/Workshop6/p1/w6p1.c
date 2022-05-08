#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

#define LOT_SIZE 15
#define COLOUR_MIN 0
#define COLOUR_MAX 2

int main(void)
{
    // C=car, P=pick-up, M=motorcycle, [any other value: n/a]
    char vehicleType[LOT_SIZE] = { 'M','P','M','C','C',
                                   'P','C','M','?','M',
                                   '?','C','P','P','C' };
    // 0=black, 1=white, 2=blue, [any other value: other]
    int colourCode[LOT_SIZE] = { 0,  1,  0,  2,  2,
                                 0,  1,  2, 99,  2,
                                -4,  0,  1,  0,  1 };
    // Positive value contains a vehicle
    int parkingSpot[LOT_SIZE] = { 172, 222, 352, 502, 422,
                                  462, 232, 182,  -1, 392,
                                    0, 252, 412, 162, 372 };
    // Estimated black book value
    double estValue[LOT_SIZE] = { 26905.0, 35020.0, 12010.0, 81000.0,     0.0,
                                  80250.0, 74060.0, 12230.0,     0.0,  8901.0,
                                      0.0, 53255.0, 36720.0,  9363.0, 19850.0 };

    int i, querying = 1, qryColour, matches;
    char qryType;
    double minValue, totalValue;

    printf("Current Parking Lot Data\n"
        "========================\n\n");

    for (i = 0; i < LOT_SIZE; i++)
    {
        if (parkingSpot[i] > 0)
        {
            printf("Spot#:%3d ", parkingSpot[i]);

            if (vehicleType[i] == 'C')
            {
                printf("CAR        ");
            }
            else if (vehicleType[i] == 'P')
            {
                printf("PICK-UP    ");
            }
            else if (vehicleType[i] == 'M')
            {
                printf("MOTORCYCLE ");
            }

            switch (colourCode[i])
            {
            case 0:
                printf("(black) ");
                break;
            case 1:
                printf("(white) ");
                break;
            case 2:
                printf("(blue)  ");
                break;
            default:
                printf("(other) ");
                break;
            }
            printf(" Est:$%9.2lf\n", estValue[i]);
        }
    }

    while (querying)
    {
        printf("\n"
            "Search Parking Lot by Vehicle Attribute\n"
            "---------------------------------------\n\n");
        printf("Match by TYPE OR COLOUR...\n");
        printf("VEHICLE TYPE OPTIONS: C=car, P=pick-up truck, M=motorcycle\n");
        printf("\tVehicle Type:   ");
        scanf(" %c", &qryType);
        printf("COLOUR OPTIONS: 0=black, 1=white, 2=blue, [any other value=other]\n");
        printf("\tVehicle Colour: ");
        scanf("%d", &qryColour);

        printf("\n"
            "Results:\n");
        printf("============================\n");
        printf("Spot#'s    : ");

        totalValue = 0.0;
        matches = 0;
        i =0;

        do {
            if (parkingSpot[i] > 0)
            {
                if (vehicleType[i] == qryType ||
                    (colourCode[i] == qryColour ||
                        (qryColour < COLOUR_MIN || qryColour > COLOUR_MAX) &&
                        (colourCode[i] < COLOUR_MIN || colourCode[i] > COLOUR_MAX)))
                {
                    printf("%d ", parkingSpot[i]);
                    totalValue += estValue[i];
                    matches++;
                }
            }
            i += 1;

        } while (i < LOT_SIZE);

        if (matches > 0)
        {
            printf("\n"
                "Matches found: %d\n"
                "Total Value  : $%9.2lf\n\n", matches, totalValue);
        }
        else
        {
            printf("---\n"
                "<NO RESULTS FOUND>\n\n");
        }

        printf("Make another query? (0=no): ");
        scanf("%d", &querying);
    };

    return 0;
}

