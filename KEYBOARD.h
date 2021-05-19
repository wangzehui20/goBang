#pragma once

#define SIZE 15
#define BLACK 10
#define WHITE 20

#include <iostream>
#include <string>

using namespace std;

class KEYBOARD {
private:
	int  symbolBoard[SIZE][SIZE];
	int  scoreBoard[SIZE][SIZE];
public:
	void displayBoard();
	void clearBoardArray();
	void setSymbolBoard(int row, int col, int value);
	void transCurChess(int row, int col, int flag);
	int  getSymbolBoard(int row, int col);
	int  symbolToNum(char col);
	char numToSymobl(int col);
};