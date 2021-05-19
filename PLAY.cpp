#include "PLAY.h"
#include <time.h>
#include <conio.h>
#include "FORBIDDEN.h"

//��ʼ��Ϸ
PLAY::PLAY() {
	while (true) {
		//��������Ϊ����ɫ
		MODE::setConsoleColor();
		int choice = MODE::chooseMode();
		//��������ָ���������
		isComputerFirst = true;
		system("cls");
		//��ʼ�����̣�ѡ��ģʽ
		keyboard.clearBoardArray();
		keyboard.displayBoard();
		compete(choice);
		if (playAgain() == false)
			break;
	}
}

PLAY::~PLAY() {

}

//��ʼ����
void PLAY::compete(int mode) {
	if (mode == 1) {
		PLAYER player1("player1", 10);
		PLAYER player2("player2", 20);
		setPlayersFlag(player1, player2);
		while (true) {
			//���1���壬Ӯ���˳�ѭ��
			playerChess(player1);
			if (judgeForbidden(player1, player2) == true)
				break;
			if (judgeVictory(player1) == true)
				break;
			//���2����
			playerChess(player2);
			if (judgeVictory(player2) == true)
				break;
		}
	}
	else if (mode == 2) {
		isComputerFirst = MODE::chooseChildMode();
		system("cls");
		keyboard.displayBoard();

		if (isComputerFirst == true)
			computerFirst();
		else
			playerFirst();
	}
	else if (mode == 3) {
		PLAYER player1("computer1", 10);
		PLAYER player2("computer2", 20);
		setPlayersFlag(player1, player2);
		while (true) {
			computerChess(player1, player2);
			if (judgeForbidden(player1, player2) == true)
				break;
			if (judgeVictory(player1) == true)
				break;
			computerChess(player2, player1);
			if (judgeVictory(player2) == true)
				break;
		}
	}
}

////������壬����������������
//void PLAY::playerChess(PLAYER &player) {
//	while (true) {
//		printf("%s input coordinate x and y (instance : 8H) :\n", player.role.c_str());
//		int row;
//		char c;
//		cin >> row >> c;
//		if (row < 1 || row > 15 || keyboard.symbolToNum(c) < 0 || keyboard.symbolToNum(c) > 14) {
//			cout << "input is valid , please input again ! \n" << endl;
//			continue;
//		}
//		player.row = row - 1;
//		player.col = keyboard.symbolToNum(c);
//		if (isPlayChess(player) == true) {
//			break;
//		}
//	}
//	keyboard.setSymbolBoard(player.row, player.col, player.flag);
//	//ˢ�����̣���Ļ��
//	system("cls");
//
//	keyboard.transCurChess(player.row, player.col, keyboard.getSymbolBoard(player.row, player.col));
//	keyboard.displayBoard();
//	keyboard.transCurChess(player.row, player.col, keyboard.getSymbolBoard(player.row, player.col));
//	printf("%s input coordinate is ( %d , %c )\n", player.role.c_str(), player.row+1, keyboard.numToSymobl(player.col));
//}

//������壬WASD�Ϳո�����ƶ�����������
void PLAY::playerChess(PLAYER &player) {
	int input;
	printf("Move: W A S D!\n%s current coordinate is ( %d , %c ):\nDecision: Space!\n", player.role.c_str(), cursorPos[0] + 1, keyboard.numToSymobl(cursorPos[1]));
	while ((input = _getch()) != 'l') {
		int row = cursorPos[0], col = cursorPos[1];
		//�ƶ�����ʱ��ʾ����
		KEYBOARD copyboard(keyboard);
		switch (input) {
		case 'w': {
			if (row - 1 >= 0) this->cursorPos[0]--;
			break;
		}
		case 's': {
			if (row + 1 < SIZE) this->cursorPos[0]++;
			break;
		}
		case 'a': {
			if (col - 1 >= 0) this->cursorPos[1]--;
			break;
		}
		case 'd': {
			if (col + 1 < SIZE) this->cursorPos[1]++;
			break;
		}
		}
		player.row = cursorPos[0], player.col = cursorPos[1];
		copyboard.setSymbolBoard(player.row, player.col, player.flag);
		system("cls");
		copyboard.transCurChess(player.row, player.col, copyboard.getSymbolBoard(player.row, player.col));
		copyboard.displayBoard();
		printf("%s current coordinate is ( %d , %c ):\nDecision: Space!\n", player.role.c_str(), player.row + 1, copyboard.numToSymobl(player.col));

		if (isPlayChess(player) == true && input == ' ') {
			break;
		}
	}
	keyboard.setSymbolBoard(player.row, player.col, player.flag);
	//ˢ�����̣���Ļ��
	system("cls");

	keyboard.transCurChess(player.row, player.col, keyboard.getSymbolBoard(player.row, player.col));
	keyboard.displayBoard();
	keyboard.transCurChess(player.row, player.col, keyboard.getSymbolBoard(player.row, player.col));
}

//���������
void PLAY::computerChess(PLAYER &selfPlayer, PLAYER &advPlayer) {
	time_t start, end;
	double cost;
	printf("-------%s is thinking-------\n", selfPlayer.role.c_str());
	time(&start);
	if (isComputerFirst == true) {
		//����������
		selfPlayer.row = selfPlayer.col = (SIZE + 1) / 2 - 1;
		/*selfPlayer.row = randFirstChess();
		selfPlayer.col = randFirstChess();*/
		keyboard.setSymbolBoard(selfPlayer.row, selfPlayer.col, selfPlayer.flag);
		isComputerFirst = false;
	}
	else {
		AI ai(selfPlayer.flag, advPlayer.flag, 2);
		ai.AIPlay(keyboard, selfPlayer.row, selfPlayer.col);
		while (true) {
			if (isPlayChess(selfPlayer) == true)
				break;
		}
		keyboard.setSymbolBoard(selfPlayer.row, selfPlayer.col, selfPlayer.flag);
	}
	system("cls");
	keyboard.transCurChess(selfPlayer.row, selfPlayer.col, keyboard.getSymbolBoard(selfPlayer.row, selfPlayer.col));
	keyboard.displayBoard();
	keyboard.transCurChess(selfPlayer.row, selfPlayer.col, keyboard.getSymbolBoard(selfPlayer.row, selfPlayer.col));

	time(&end);
	cost = difftime(end, start);
	printf("%s input coordinate is ( %d , %c ), cost time is %f s\n", selfPlayer.role.c_str(), selfPlayer.row + 1, keyboard.numToSymobl(selfPlayer.col), cost);
}

//���������������壬�������
void PLAY::playerFirst() {
	PLAYER player1("player", 10);
	PLAYER player2("computer", 20);
	setPlayersFlag(player1, player2);
	while (true) {
		//���1���壬Ӯ���˳�ѭ��
		playerChess(player1);
		if (judgeForbidden(player1, player2) == true)
			break;
		if (judgeVictory(player1) == true)
			break;
		//���2����
		computerChess(player2, player1);
		if (judgeVictory(player2) == true)
			break;
	}
}

//���������������壬���������
void PLAY::computerFirst() {
	PLAYER player1("computer", 10);
	PLAYER player2("player", 20);
	setPlayersFlag(player1, player2);
	while (true) {
		computerChess(player1, player2);
		if (judgeForbidden(player1, player2) == true)
			break;
		if (judgeVictory(player1) == true || isPeace(player1, player2) == true)
			break;
		playerChess(player2);
		if (judgeVictory(player2) == true || isPeace(player1, player2) == true)
			break;
	}
}

//�����������������
void PLAY::setPlayersFlag(PLAYER player1, PLAYER player2) {
	flag1 = player1.flag;
	flag2 = player2.flag;
}

//�ж��Ƿ�ʤ��
bool PLAY::judgeVictory(PLAYER player) {
	if (isVictory(player) == true) {
		printf("%s wins!\n", player.role.c_str());
		return true;
	}
	return false;
}

//�ж��Ƿ�ʤ���Ĺ���
bool PLAY::isVictory(PLAYER player) {
	int begin, end;
	int row = player.row;
	int col = player.col;
	int flag = player.flag;

	//�ж�ˮƽ����
	col - 4 >= 0 ? begin = col - 4 : begin = 0;
	col + 4 < SIZE ? end = col + 4 : end = SIZE - 1;
	for (int i = row, j = begin; j + 4 <= end; ++j) {
		if ((keyboard.getSymbolBoard(i, j) == flag) &&
			(keyboard.getSymbolBoard(i, j + 1) == flag) &&
			(keyboard.getSymbolBoard(i, j + 2) == flag) &&
			(keyboard.getSymbolBoard(i, j + 3) == flag) &&
			(keyboard.getSymbolBoard(i, j + 4) == flag))
			return true;
	}

	//�ж���ֱ����
	row - 4 >= 0 ? begin = row - 4 : begin = 0;
	row + 4 < SIZE ? end = row + 4 : end = SIZE - 1;
	for (int i = begin, j = col; i + 4 <= end; ++i) {
		if ((keyboard.getSymbolBoard(i, j) == flag) &&
			(keyboard.getSymbolBoard(i + 1, j) == flag) &&
			(keyboard.getSymbolBoard(i + 2, j) == flag) &&
			(keyboard.getSymbolBoard(i + 3, j) == flag) &&
			(keyboard.getSymbolBoard(i + 4, j) == flag))
			return true;
	}

	//�ж����Խ��߷�������->����

	//��Գ���
	int len;
	int start, finish;
	row > col ? len = col : len = row;
	if (len > 4)
		len = 4;
	//begin��������ʼλ��,start��������ʼλ��
	begin = row - len;
	start = col - len;

	row > col ? len = SIZE - 1 - row : len = SIZE - 1 - col;
	if (len > 4)
		len = 4;
	//end���������λ��,finish���������λ��
	end = row + len;
	finish = col + len;

	for (int i = begin, j = start; i + 4 <= end, j + 4 <= finish; ++i, ++j) {
		if ((keyboard.getSymbolBoard(i, j) == flag) &&
			(keyboard.getSymbolBoard(i + 1, j + 1) == flag) &&
			(keyboard.getSymbolBoard(i + 2, j + 2) == flag) &&
			(keyboard.getSymbolBoard(i + 3, j + 3) == flag) &&
			(keyboard.getSymbolBoard(i + 4, j + 4) == flag))
			return true;
	}

	//�жϸ��Խ��߷�������->����
	len = SIZE - 1 - row > col ? col : SIZE - 1 - row;
	if (len > 4)
		len = 4;
	begin = row + len;
	start = col - len;

	len = SIZE - 1 - col > row ? row : SIZE - 1 - col;
	if (len > 4)
		len = 4;
	end = row - len;
	finish = col + len;

	for (int i = begin, j = start; i - 4 >= end, j <= finish; --i, ++j)
		if ((keyboard.getSymbolBoard(i, j) == flag) &&
			(keyboard.getSymbolBoard(i - 1, j + 1) == flag) &&
			(keyboard.getSymbolBoard(i - 2, j + 2) == flag) &&
			(keyboard.getSymbolBoard(i - 3, j + 3) == flag) &&
			(keyboard.getSymbolBoard(i - 4, j + 4) == flag))
			return true;
	return false;
}

//�Ƿ�����һ��
bool PLAY::playAgain() {
	cout << "Do you want to play again, yes or no?" << endl;
	string str;
	cin >> str;
	if (str == "no")
		return false;
	if (str == "yes")
		return true;
}

//����λ���Ƿ���������
bool PLAY::isPlayChess(PLAYER player) {
	int row = player.row;
	int col = player.col;
	if (row >= 0 && row < SIZE && col >= 0 && col < SIZE) {
		if (keyboard.getSymbolBoard(row, col) != flag1 && keyboard.getSymbolBoard(row, col) != flag2)
			return true;
	}
	cout << "this location has chessman!" << endl;
	return false;
}

//�Ƿ�;�
bool PLAY::isPeace(PLAYER player1, PLAYER player2) {
	for (int i = 0; i < SIZE - 1; ++i)
		for (int j = 0; j < SIZE - 1; ++j)
			if (keyboard.getSymbolBoard(i, j) != player1.flag &&
				keyboard.getSymbolBoard(i, j) != player2.flag)
				return false;
	cout << "Game is Peace!" << endl;
	return true;
}

//�жϽ���
bool PLAY::judgeForbidden(PLAYER player1, PLAYER player2) {
	int** tBoard = transBoard(player1, player2);
	FORBIDDEN forbidden(tBoard, SIZE, SIZE);
	//ֻ�迼�Ǹ��µĺ���
	return forbidden.isForbidden(player1.row, player1.col);
}

//��һ�����ڷ���Ԫ��
int PLAY::randFirstChess() {
	srand((int)time(0));
	//�������3-11֮�䣬��Ϊ���ڱ߽Ǵ�û������
	int randChess = rand() % (SIZE - 7) + 3;
	return randChess;
}

int** PLAY::transBoard(PLAYER player1, PLAYER player2) {
	//����ת�������븳ֵ����AI.h�в��ִ����غ�
	int **tBoard = new int*[SIZE];
	for (int i = 0; i < SIZE; ++i)
		tBoard[i] = new int[SIZE];
	for (int i = 0; i < SIZE; ++i) {
		for (int j = 0; j < SIZE; ++j) {
			if (keyboard.getSymbolBoard(i, j) == player1.flag)
				tBoard[i][j] = 1;
			else if (keyboard.getSymbolBoard(i, j) == player2.flag)
				tBoard[i][j] = 2;
			else
				tBoard[i][j] = 0;
		}
	}
	return tBoard;
}

