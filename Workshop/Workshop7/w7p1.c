/*
*****************************************************************************
                          Workshop - #7 (P1)
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
#define MAX_LIVES 10
#define MIN_LIVES 1 
#define MAX_LENGTH 70
#define MIN_LENGTH 10
#define MAX_LIMIT 26
#define MIN_LIMIT 3
struct PlayerInfo
{
	char name;
	int lives;
	int treasures_found;
	int entered_position[MAX_LENGTH];
};
struct GameInfo
{
	int length;
	int limit;
	int bomb[MAX_LENGTH];
	int treasures[MAX_LENGTH];
};
int main(void)
{
	struct GameInfo game;
	struct PlayerInfo player;
	int i;
	printf("================================\n");
	printf("         Treasure Hunt!\n");
	printf("================================\n\n");
	printf("PLAYER Configuration\n");
	printf("--------------------\n");
	printf("Enter a single character to represent the player: ");
	scanf("%c", &player.name);
	do
	{
		printf("Set the number of lives: ");
		scanf("%d", &player.lives);
		if (player.lives < MIN_LIVES || player.lives >MAX_LIVES)
		{
			printf("     Must be between 1 and 10!\n");
		}
	} while (player.lives < MIN_LIVES || player.lives >MAX_LIVES);
	printf("Player configuration set-up is complete\n\n");
	printf("GAME Configuration\n");
	printf("------------------\n");
	do
	{
		printf("Set the path length (a multiple of 5 between 10-70): ");
		scanf("%d", &game.length);
		if (game.length<MIN_LENGTH || game.length> MAX_LENGTH || game.length % 5 != 0)
		{
			printf("     Must be a multiple of 5 and between 10-70!!!\n");
		}

	} while (game.length<MIN_LENGTH || game.length> MAX_LENGTH || game.length % 5 != 0);
	do
	{
		printf("Set the limit for number of moves allowed: ");
		scanf("%d", &game.limit);
		if (game.limit < MIN_LIMIT || game.limit > MAX_LIMIT)
		{
			printf("    Value must be between 3 and 26\n");
		}
	} while (game.limit < MIN_LIMIT || game.limit > MAX_LIMIT);

	printf("\nBOMB Placement\n");
	printf("--------------\n");
	printf("Enter the bomb positions in sets of 5 where a value\n");
	printf("of 1=BOMB, and 0=NO BOMB. Space-delimit your input.\n");
	printf("(Example: 1 0 0 1 1) NOTE: there are %d to set!\n", game.length);

	for (i = 0;i < game.length;i += 5)
	{

		printf("   Positions [%2d-%2d]: ", i + 1, i + 5);
		scanf("%d %d %d %d %d", &game.bomb[i], &game.bomb[i + 1], &game.bomb[i + 2], &game.bomb[i + 3], &game.bomb[i + 4]);

	}
	printf("BOMB placement set\n\n");
	printf("TREASURE Placement\n");
	printf("------------------\n");
	printf("Enter the treasure placements in sets of 5 where a value\n");
	printf("of 1=TREASURE, and 0=NO TREASURE. Space-delimit your input.\n");
	printf("(Example: 1 0 0 1 1) NOTE: there are %d to set!\n", game.length);

	for (i = 0;i < game.length;i += 5)
	{
		printf("   Positions [%2d-%2d]: ", i + 1, i + 5);
		scanf("%d %d %d %d %d", &game.treasures[i], &game.treasures[i + 1], &game.treasures[i + 2], &game.treasures[i + 3], &game.treasures[i + 4]);
	}
	printf("TREASURE placement set\n\n");
	printf("GAME configuration set-up is complete...\n\n");
	printf("------------------------------------\n");
	printf("TREASURE HUNT Configuration Settings\n");
	printf("------------------------------------\n");
	printf("Player:\n");
	printf("   Symbol     : %c\n", player.name);
	printf("   Lives      : %d\n", player.lives);
	printf("   Treasure   : [ready for gameplay]\n");
	printf("   History    : [ready for gameplay]\n\n");
	printf("Game:\n");
	printf("   Path Length: %d\n", game.length);
	printf("   Bombs      : ");
	for (i = 0; i < game.length; i++)
	{
		printf("%d", game.bomb[i]);
	}
	printf("\n");
	printf("   Treasure   : ");
	for (i = 0;i < game.length;i++)
	{
		printf("%d", game.treasures[i]);
	}

	printf("\n\n====================================\n");
	printf("~ Get ready to play TREASURE HUNT! ~\n");
	printf("====================================\n");
	return 0;
}
