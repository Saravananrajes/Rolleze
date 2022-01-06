#include <stdio.h>
#include <math.h>
#include <time.h>
#include <string.h>
#include <stdlib.h>
#include "prototypes.h"

int main() {

	menu();
	unsigned short int round = 1;
	diceStruct print;
	scores points;
	print = initldice();
	points = initlpoints();

	while (round < 12) {
		char input[7];

		printf("\nDo you want to Score, Roll or Quit\n");
		scanf_s("%s", &input, 7);
		srand(time(0));
		if ((strcmp(input, "Roll") == 0 || strcmp(input, "roll") == 0) && print.RollNumber < 3) {
			dice_Roll(&print);
			print_dice(&print);

		}
		else if (strcmp(input, "Score") == 0 || strcmp(input, "score") == 0) {
			print_Score(&points);
			points = Update_Score(points, &points, print);
			print.RollNumber = 0; // resets rolls to 0
			round += 1;
		}
		else if (strcmp(input, "Quit") == 0 || strcmp(input, "quit") == 0) {
			FinalScore(&points);
			printf("\nGoodbye!\n");
			return 0;
		}
		else printf("\nInvalid input\n");
	}
	FinalScore(&points);
	printf("\nGoodbye!\n");
	return 0;
}