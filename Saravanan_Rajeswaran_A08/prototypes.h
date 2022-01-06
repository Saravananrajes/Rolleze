struct diceStruct {
	unsigned short int DiceRolls[5];
	unsigned short int RollNumber;
};

struct scores {
	unsigned short int playerscore[11];
	bool points[11];
	char pointnames[11][12] = { "1s", "2s", "3s", "4s", "5s", "6s", "3 of a kind", "4 of a kind", "Full house", "Yahtzee", "Chance" };
};

diceStruct initldice();
scores initlpoints();
void menu(void);
diceStruct* dice_Roll(diceStruct* Rolls);
void print_dice(diceStruct Roll[]);
void print_Score(scores* numbers);
scores Update_Score(scores update, scores* number, diceStruct roll);
unsigned short int* freezDice(unsigned short int freezDice[]);
void FinalScore(scores* final);
