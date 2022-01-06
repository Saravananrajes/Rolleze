#include <stdio.h>
#include <math.h>
#include <time.h>
#include <string.h>
#include <stdlib.h>
#include "prototypes.h"

diceStruct initldice() {
	diceStruct dice;
	for (int i = 0; i < 5; i++) {
		dice.DiceRolls[i] = 0;
	}
	dice.RollNumber = 0;
	return dice;
}

scores initlpoints() {
	scores point;
	for (int i = 0; i < 11; i++) {
		point.playerscore[i] = 0;
		point.points[i] = false;
	}
	return point;
}

void menu(void) {
	char name[20];
	srand(time(0));
	printf("--------------------------------------------\n");
	printf("-------------Welcome to Rolleze-------------\n");
	printf("--------------------------------------------\n");

	printf("Enter your name ");
	scanf_s("%s", name, 20);

	strnlen(name, 20);
	printf("\n------------- Welcome %s ------------\n", name);
}

diceStruct* dice_Roll(diceStruct* Rolls) {
	unsigned short int freezeArr[5] = { 0 };
	unsigned short int* freezePtr = freezeArr;
	Rolls->RollNumber += 1;
	if (Rolls->RollNumber != 1) {
		freezePtr = freezDice(freezeArr);
	}
	for (int i = 0; i < 5; i++) {
		if (*(freezePtr + i) == 1) {
			continue;
		}
		else if (*(freezePtr + i) == 0) {
			Rolls->DiceRolls[i] = (rand() % 6 + 1);
		}
	}

	return Rolls;
}

void print_dice(diceStruct Roll[]) {
	printf("\n-------------------------------\n");
	printf("This is roll number %hu \n", Roll->RollNumber);
	printf("-------------------------------\n\n");
	printf("-----   -----   -----   -----   ----- \n");

	int i = 0;
	int j = 1;
	while (j <= 3) {
		i = 0;
		switch (j) {
		case 1:
			while (i < 5) {

				switch (Roll->DiceRolls[i]) {

				case 1:
					printf("|   |   ");
					break;
				case 2:
					printf("|*  |   ");
					break;
				case 3:
					printf("|*  |   ");
					break;
				case 4:
					printf("|* *|   ");
					break;
				case 5:
					printf("|* *|   ");
					break;
				case 6:
					printf("|* *|   ");
					break;
				}
				i++;
			}
			j++;
			i = 0;
			printf("\n");
			break;
		case 2:
			while (i < 5) {

				switch (Roll->DiceRolls[i]) {

				case 1:
					printf("| * |   ");
					break;
				case 2:
					printf("|   |   ");
					break;
				case 3:
					printf("| * |   ");
					break;
				case 4:
					printf("|   |   ");
					break;
				case 5:
					printf("| * |   ");
					break;
				case 6:
					printf("|* *|   ");
					break;
				}
				i++;
			}
			j++;
			i = 0;
			printf("\n");
			break;

		case 3:
			while (i < 5) {

				switch (Roll->DiceRolls[i]) {

				case 1:
					printf("|   |   ");
					break;
				case 2:
					printf("|  *|   ");
					break;
				case 3:
					printf("|  *|   ");
					break;
				case 4:
					printf("|* *|   ");
					break;
				case 5:
					printf("|* *|   ");
					break;
				case 6:
					printf("|* *|   ");
					break;
				}
				i++;
			}
			j++;
			i = 0;
			printf("\n");
			break;
		}
	}
	printf("-----   -----   -----   -----   -----\n");

}

void print_Score(scores* numbers) {
	printf("\n----------------------\n");
	printf("\n------Score Sheet-----\n");
	printf("\n----------------------\n");
	for (int i = 0; i < 11; i++) {
		printf("%d %s %hu", i + 1, numbers->pointnames[i], numbers->playerscore[i]);
		printf("\n");
	}

}

scores Update_Score(scores update, scores* number, diceStruct roll) {

	unsigned short int input = 0;
	unsigned short int check[6] = { 0 };
	while (1) {
		printf("Enter the point name index you want to score (1 - 11): \n");
		scanf_s("%hu", &input);
		//Checks for a input of 1 - 6
		if ((1 <= input && input <= 6) && update.points[input - 1] == false) {
			for (int i = 0; i < 5; i++) {
				if (input == roll.DiceRolls[i]) {
					update.playerscore[input - 1] += roll.DiceRolls[i];
				}

			}
			update.points[input - 1] == true;
			break;
		}
		// Checks for 3 of a kind and 4 of a kind
		else if ((7 <= input && input <= 8) && update.points[input - 1] == false) {
			for (int i = 0; i < 5; i++) {
				check[roll.DiceRolls[i] - 1] += 1;
			}

			for (int i = 0; i < 6; i++) {
				if (check[i] == (input - 4)) {
					for (int i = 0; i < 5; i++) {
						update.playerscore[input - 1] += roll.DiceRolls[i];
					}
					break;
				}

			}
			update.points[input - 1] == true;
			break;
		}
		// Checks for full house
		else if ((input == 9) && update.points[input - 1] == false) {
			for (int i = 0; i < 5; i++) {
				check[roll.DiceRolls[i] - 1] += 1;
			}

			for (int i = 0; i < 6; i++) {
				if (check[i] == 3) {
					for (int i = 0; i < 6; i++) {
						if (check[i] == 2) {
							update.playerscore[input - 1] += 25;
						}
					}
					break;
				}

			}
			update.points[input - 1] == true;
			break;
		}

		// Checks for Yahtzee
		else if ((input == 10) && update.points[input - 1] == false) {
			for (int i = 0; i < 5; i++) {
				check[roll.DiceRolls[i] - 1] += 1;
			}

			for (int i = 0; i < 6; i++) {
				if (check[i] == 5) {
					update.playerscore[input - 1] += 50;
					break;
				}

			}
			update.points[input - 1] == true;
			break;
		}

		// Checks for chance
		else if ((input == 11) && update.points[input - 1] == false) {
			for (int i = 0; i < 5; i++) {
				update.playerscore[input - 1] += roll.DiceRolls[i];
			}
			update.points[input - 1] == true;
			break;
		}

		//if input was not between 1 to 11
		else {
			printf("Invalid input \n");
		}

	}
	printf("\n----------------------\n");
	printf("\n------Score Sheet-----\n");
	printf("\n----------------------\n");
	for (int i = 0; i < 11; i++) {
		printf("%d %s %hu", i + 1, number->pointnames[i], update.playerscore[i]);
		printf("\n");
	}
	return update;
}

unsigned short int* freezDice(unsigned short int freezDice[]) {
	unsigned int freezeinput;
	printf("\nwhich dice would you like to freeze? put 1 to freeze and put 0 to skip, (ex: typing 10101 will freeze dice 1, 3 and 5): ");
	scanf_s("%d", &freezeinput);

	for (int i = 0; i < 5; i++) {
		freezDice[4 - i] = freezeinput % 10;
		freezeinput /= 10;
	}
	return freezDice;
}

void FinalScore(scores* final) {
	unsigned short int finalscore = 0;
	print_Score(final);
	for (int i = 0; i < 11; i++) {
		finalscore += final->playerscore[i];
	}
	printf("\nyour final score is: %hu\n", finalscore);
}