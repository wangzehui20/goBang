#include "KEYBOARD.h"

void KEYBOARD::displayBoard() {
	int i, j;
	cout << "BLACK : ●, NOW_BLACK : ▲, WHITE : ◎, NOW_WHITE : △" << endl;
	for (i = 0; i <= SIZE - 1; i++)
	{
		//打印列的序号
		if (i == 0) {
			cout << "  ";
			cout << "A B C D E F G H I J K L M N O" << endl;
		}
		//打印行的序号
		i <= 8 ? printf("%d ", i + 1) : printf("%d", i + 1);
		for (j = 0; j <= SIZE - 1; j++)
		{
			switch (symbolBoard[i][j] % 100)//%100为了适应将来有分值的情形
			{
			case 1:
				printf("┏");
				break;

			case 2:
				printf("┓");
				break;

			case 3:
				printf("┛");
				break;

			case 4:
				printf("┗");
				break;

			case 5:
				printf("┠");
				break;

			case 6:
				printf("┯");
				break;

			case 7:
				printf("┨");
				break;

			case 8:
				printf("┷");
				break;

			case 9:
				printf("┼");
				break;

			case 10:
				printf("●");
				break;

			case 11:
				printf("▲");
				break;

			case 20:
				printf("◎");
				break;

			case 21:
				printf("△");
				break;

			}
			if (j == 14)
			{
				printf("\n");
			}
		}
	}
}

void KEYBOARD::clearBoardArray() {
	int i, j; //i＝行，j＝列

	symbolBoard[0][0] = 1;
	symbolBoard[0][SIZE - 1] = 2;
	symbolBoard[SIZE - 1][SIZE - 1] = 3;
	symbolBoard[SIZE - 1][0] = 4;

	for (i = 1; i < SIZE - 1; i++)
	{
		symbolBoard[i][0] = 5;
	}

	for (i = 1; i < SIZE - 1; i++)
	{
		symbolBoard[i][SIZE - 1] = 7;
	}

	for (j = 1; j < SIZE - 1; j++)
	{
		symbolBoard[0][j] = 6;
	}
	for (j = 1; j < SIZE - 1; j++)
	{
		symbolBoard[SIZE - 1][j] = 8;
	}

	for (i = 1; i < SIZE - 1; i++)
	{
		for (j = 1; j < SIZE - 1; j++)
		{
			symbolBoard[i][j] = 9;
		}
	}
}

void KEYBOARD::setSymbolBoard(int row, int col, int value) {
	symbolBoard[row][col] = value;
}

void KEYBOARD::transCurChess(int row, int col, int flag) {
	int curFlag;
	if (flag == 10)curFlag = 11;
	else if (flag == 11)curFlag = 10;
	else if (flag == 20)curFlag = 21;
	else if (flag == 21)curFlag = 20;
	this->setSymbolBoard(row, col, curFlag);
}

int KEYBOARD::getSymbolBoard(int row, int col) {
	return symbolBoard[row][col];
}

int KEYBOARD::symbolToNum(char col) {
	switch (col)
	{
	case 'A':
		return 0;

	case 'B':
		return 1;

	case 'C':
		return 2;

	case 'D':
		return 3;

	case 'E':
		return 4;

	case 'F':
		return 5;

	case 'G':
		return 6;

	case 'H':
		return 7;

	case 'I':
		return 8;

	case 'J':
		return 9;

	case 'K':
		return 10;

	case 'L':
		return 11;

	case 'M':
		return 12;

	case 'N':
		return 13;

	case 'O':
		return 14;
	}
}

char KEYBOARD::numToSymobl(int col) {
	switch (col)
	{
	case 0:
		return 'A';

	case 1:
		return 'B';

	case 2:
		return 'C';

	case 3:
		return 'D';

	case 4:
		return 'E';

	case 5:
		return 'F';

	case 6:
		return 'G';

	case 7:
		return 'H';

	case 8:
		return 'I';

	case 9:
		return 'J';

	case 10:
		return 'K';

	case 11:
		return 'L';

	case 12:
		return 'M';

	case 13:
		return 'N';

	case 14:
		return 'O';
	}
}