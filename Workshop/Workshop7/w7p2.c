/*
*****************************************************************************
                          Workshop - #7 (P2)
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
#define MAX_LIMIT 15
#define MIN_LIMIT 3
struct Playinfo
{
	int lives;
	char name;
	int treasure;
	int history[MAX_LENGTH];
};
struct Gameinfo
{
	int length;
	int limit;
	int bombs[MAX_LENGTH];
	int treasures[MAX_LENGTH];
};
int main(void)
{
	
	const int tencyc = 10;
	int  flag = 0, flag1 = 0; //flag var
	int i;
	struct Playinfo player;
	struct Gameinfo game;
	int num;

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
			printf("    Value must be between 3 and 15\n");
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
		scanf("%d %d %d %d %d", &game.bombs[i], &game.bombs[i + 1], &game.bombs[i + 2], &game.bombs[i + 3], &game.bombs[i + 4]);

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
		printf("%d", game.bombs[i]);
	}
	printf("\n");
	printf("   Treasure   : ");
	for (i = 0;i < game.length;i++)
	{
		printf("%d", game.treasures[i]);
	}

	printf("\n\n====================================\n");
	printf("~ Get ready to play TREASURE HUNT! ~\n");
	printf("====================================\n\n");

	for (i = 0; i < game.length; i++)
	{
		player.history[i] = 0;
	}
	player.treasure = 0;
	printf("  ");
	for (i = 0; i < game.length; i++)
	{
		if (player.history[i] == 0)
		{
			printf("-");
		}
		else if (player.history[i] == 1)
		{
			printf(".");
		}
		else if (player.history[i] == 2)
		{
			printf("!");
		}
		else if (player.history[i] == 3)
		{
			printf("$");
		}
		else if (player.history[i] == 4)
		{
			printf("&");
		}
	}
	printf("\n  ");
	for (i = 1; i <= game.length; i++)
	{
		if (i % tencyc == 0)
		{
			printf("%d", i / tencyc);
		}
		else
		{
			printf("|");
		}
	}
	printf("\n  ");
	for (i = 1; i <= game.length; i++)
	{
		if (i % tencyc == 0)
		{
			printf("0");
		}
		else
		{
			printf("%d", i % tencyc);
		}
	}
	printf("\n");
	printf("+---------------------------------------------------+\n");
	printf("  Lives: %2d  | Treasures: %2d  |  Moves Remaining: %2d\n", player.lives, player.treasure, game.limit);
	printf("+---------------------------------------------------+\n");
	do
	{
		do
		{
			printf("Next Move [1-%d]: ", game.length);
			scanf("%d", &num);
			if (num < MIN_LIVES || num > game.length)
			{
				printf("  Out of Range!!!\n");
			}
			else
			{
				flag = 1;
			}
		} while (flag == 0);
		num -= 1;
		if (player.history[num] == 0)
		{
			if (game.bombs[num] == 1 && game.treasures[num] == 1)
			{
				printf("\n===============> [&] !!! BOOOOOM !!! [&]\n");
				printf("===============> [&] $$$ Life Insurance Payout!!! [&]");
				player.history[num] = 4;
				player.lives--;
				player.treasure++;
			}
			else if (game.bombs[num] == 1)
			{
				printf("\n===============> [!] !!! BOOOOOM !!! [!]");
				player.history[num] = 2;
				player.lives--;
				if (player.lives == 0)
				{
					printf("\n\nNo more LIVES remaining!");
				}
			}
			else if (game.treasures[num] == 1)
			{
				printf("\n===============> [$] $$$ Found Treasure! $$$ [$]");
				player.history[num] = 3;
				player.treasure++;
			}
			else
			{
				printf("\n===============> [.] ...Nothing found here... [.]");
				player.history[num] = 1;
			}
			game.limit--;
		}
		else
		{
			printf("\n===============> Dope! You've been here before!");
		}
		printf("\n\n  ");
		flag1 = 0;
		for (i = 0; i < game.length&&flag1!=1; i++)
		{
			
			if (i == num)
			{
				printf("%c", player.name);
				flag1 = 1;
			}
			else
			{
				printf(" ");
			}
		}
		printf("\n  ");
		for (i = 0; i < game.length; i++)
		{
			if (player.history[i] == 0)
			{
				printf("-");
			}
			else if (player.history[i] == 1)
			{
				printf(".");
			}
			else if (player.history[i] == 2)
			{
				printf("!");
			}
			else if (player.history[i] == 3)
			{
				printf("$");
			}
			else if (player.history[i] == 4)
			{
				printf("&");
			}
		}
		printf("\n  ");
		for (i = 1; i <= game.length; i++)
		{
			if (i % tencyc == 0)
			{
				printf("%d", i / tencyc);
			}
			else
			{
				printf("|");
			}
		}
		printf("\n  ");
		for (i = 1; i <= game.length; i++)
		{
			if (i % tencyc == 0)
			{
				printf("0");
			}
			else
			{
				printf("%d", i % tencyc);
			}
		}
		printf("\n");
		printf("+---------------------------------------------------+\n");
		printf("  Lives: %2d  | Treasures: %2d  |  Moves Remaining: %2d\n", player.lives, player.treasure, game.limit);
		printf("+---------------------------------------------------+\n");
		flag = 0;
	} while (game.limit > 0 && player.lives > 0);
	printf("\n##################\n");
	printf("#   Game over!   #\n");
	printf("##################\n\n");
	printf("You should play again and try to beat your score!\n");
	return 0;
}