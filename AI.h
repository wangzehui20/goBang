#pragma once

#define DEPTH     6
#define TOPK      5
#define STRIDE    2

//���ʹ��� �±� //Ȩ��
#define OTHER     0		//0

#define WIN       1		//1000000
//����͡��塱��������������˶�û�б����ϣ������塱�������һ�˱�������
#define FLEX4     2		//50000
#define BLOCK4    3		//8000
#define FLEX3     4		//5000
#define BLOCK3    5		//50
#define FLEX2     6		//60
#define BLOCK2    7		//1
#define FLEX1     8		//1
//Adversary����
#define LOSE      9		//-1200000
#define ADVFLEX4  10    //-60000
#define ADVBLOCK4 11    //-9000
#define ADVFLEX3  12    //-6000
#define ADVBLOCK3 13    //-50
#define ADVFLEX2  14    //-60
#define ADVBLOCK2 15    //-1
#define ADVFLEX1  16    //-1

#include "KEYBOARD.h"
#include <iostream>
using namespace std;

struct Position {
	int x;
	int y;
};

struct Points {
	Position pos[TOPK];
	int score[TOPK];
};

struct Decision {
	Position dPos;
	int dScore;
};

class AI {
	Decision decision;
private:
	//�������Σ�0�����λ��1�����Լ������ӣ�2������ֵ����ӣ�3����߽�
	int chessStatus[4][4][4][4][4][4] = { {{{{{0}}}}} };
	int selfFlag, advFlag;
	//theta�������1��Ϊ�����ͣ�С��1��Ϊ������
	float theta;
	int weight[17] = { 0, 1000000,50000,8000,5000,50,60,1,1,-1200000, -60000,-9000 ,-6000,-50,-60,-1,-1 };

public:
	AI(int selfFlag, int advFlag, float theta);
	void initChessStatus();
	void AIPlay(KEYBOARD board, int &x, int &y);
	void setBlock(int p1, int p2, int p3, int p4, int p5, int p6, int block);
	void matchShapeRecord(int **shape, int **board);
	void delete2DArray(int **arr, int row);
	int evaluation(KEYBOARD board);
	Points localSearch(KEYBOARD board);
	int maxMinSearch(KEYBOARD board, int depth, int alpha, int beta);
	int** extendBoard(KEYBOARD board);
	int* setWeight();
	int** create2DArray(int row, int col);
	KEYBOARD inverseBoard(KEYBOARD board, int row, int col);
	bool isVictory(KEYBOARD board);
};