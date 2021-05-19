#pragma once
#include "MODE.h"
#include "PLAYER.h"
#include "AI.h"

class PLAY {
private:
	KEYBOARD keyboard;
	int cursorPos[2] = { SIZE / 2, SIZE / 2 };
	//���1�����2�����ӱ�־�������ж����̵�ĳλ���Ƿ�������
	int flag1, flag2;
	//������Ƿ�����
	bool isComputerFirst = true;
public:
	PLAY();
	~PLAY();
	void compete(int mode);
	void playerChess(PLAYER &player);
	void computerChess(PLAYER &selfPlayer, PLAYER &advPlayer);
	void playerFirst();
	void computerFirst();
	void setPlayersFlag(PLAYER player1, PLAYER player2);
	bool judgeVictory(PLAYER player);
	bool isVictory(PLAYER player);
	bool playAgain();
	bool isPlayChess(PLAYER player);
	bool isPeace(PLAYER player1, PLAYER player2);
	bool judgeForbidden(PLAYER player1, PLAYER player2);
	int randFirstChess();
	int** transBoard(PLAYER player1, PLAYER player2);
};