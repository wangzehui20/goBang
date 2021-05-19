#include "AI.h"

AI::AI(int selfFlag, int advFlag, float theta) {
	this->selfFlag = selfFlag;
	this->advFlag = advFlag;
	this->theta = theta;
	initChessStatus();
}

void AI::initChessStatus() {
	//������5����Ӯ
	this->chessStatus[0][1][1][1][1][1] = WIN;
	this->chessStatus[1][1][1][1][1][0] = WIN;
	this->chessStatus[2][1][1][1][1][1] = WIN;
	this->chessStatus[1][1][1][1][1][2] = WIN;
	this->chessStatus[3][1][1][1][1][1] = WIN;
	this->chessStatus[1][1][1][1][1][3] = WIN;

	//������5������
	this->chessStatus[0][2][2][2][2][2] = LOSE;
	this->chessStatus[2][2][2][2][2][0] = LOSE;
	this->chessStatus[1][2][2][2][2][2] = LOSE;
	this->chessStatus[2][2][2][2][2][1] = LOSE;
	this->chessStatus[3][2][2][2][2][2] = LOSE;
	this->chessStatus[2][2][2][2][2][3] = LOSE;

	//������4
	this->chessStatus[0][1][1][1][1][0] = FLEX4;

	//���ֻ�4
	this->chessStatus[0][2][2][2][2][0] = ADVFLEX4;

	//������3
	this->chessStatus[0][1][1][1][0][0] = FLEX3;
	this->chessStatus[0][0][1][1][1][0] = FLEX3;
	this->chessStatus[0][1][0][1][1][0] = FLEX3;
	this->chessStatus[0][1][1][0][1][0] = FLEX3;

	//���ֻ�3
	this->chessStatus[0][2][2][2][0][0] = ADVFLEX3;
	this->chessStatus[0][0][2][2][2][0] = ADVFLEX3;
	this->chessStatus[0][2][0][2][2][0] = ADVFLEX3;
	this->chessStatus[0][2][2][0][2][0] = ADVFLEX3;

	//������2
	this->chessStatus[0][1][1][0][0][0] = FLEX2;
	this->chessStatus[0][1][0][1][0][0] = FLEX2;
	this->chessStatus[0][1][0][0][1][0] = FLEX2;
	this->chessStatus[0][0][1][1][0][0] = FLEX2;
	this->chessStatus[0][0][1][0][1][0] = FLEX2;
	this->chessStatus[0][0][0][1][1][0] = FLEX2;

	//���ֻ�2
	this->chessStatus[0][2][2][0][0][0] = ADVFLEX2;
	this->chessStatus[0][2][0][2][0][0] = ADVFLEX2;
	this->chessStatus[0][2][0][0][2][0] = ADVFLEX2;
	this->chessStatus[0][0][2][2][0][0] = ADVFLEX2;
	this->chessStatus[0][0][2][0][2][0] = ADVFLEX2;
	this->chessStatus[0][0][0][2][2][0] = ADVFLEX2;

	//������1
	this->chessStatus[0][1][0][0][0][0] = FLEX1;
	this->chessStatus[0][0][1][0][0][0] = FLEX1;
	this->chessStatus[0][0][0][1][0][0] = FLEX1;
	this->chessStatus[0][0][0][0][1][0] = FLEX1;

	//���ֻ�1
	this->chessStatus[0][2][0][0][0][0] = ADVFLEX1;
	this->chessStatus[0][0][2][0][0][0] = ADVFLEX1;
	this->chessStatus[0][0][0][2][0][0] = ADVFLEX1;
	this->chessStatus[0][0][0][0][2][0] = ADVFLEX1;

	//p1-p6�ֱ����chessStatus�еĲ�ͬά�ȣ�leftSelf��5�е��Լ����Ӹ�����leftAdv��5�еĵ������Ӹ���
	//rightSelf��5�е��Լ����Ӹ�����rightAdv��5�еĵ������Ӹ���
	int p1, p2, p3, p4, p5, p6, leftSelf, leftAdv, rightSelf, rightAdv;
	for (p1 = 0; p1 < 4; ++p1) {
		for (p2 = 0; p2 < 4; ++p2) {
			for (p3 = 0; p3 < 4; ++p3) {
				for (p4 = 0; p4 < 4; ++p4) {
					for (p5 = 0; p5 < 4; ++p5) {
						for (p6 = 0; p6 < 4; ++p6) {
							leftSelf = leftAdv = rightSelf = rightAdv = 0;

							if (p1 == 1)leftSelf++;
							else if (p1 == 2)leftAdv++;
							if (p2 == 1) { leftSelf++; rightSelf++; }
							else if (p2 == 2) { leftAdv++, rightAdv++; }
							if (p3 == 1) { leftSelf++; rightSelf++; }
							else if (p3 == 2) { leftAdv++, rightAdv++; }
							if (p4 == 1) { leftSelf++; rightSelf++; }
							else if (p4 == 2) { leftAdv++, rightAdv++; }
							if (p5 == 1) { leftSelf++; rightSelf++; }
							else if (p5 == 2) { leftAdv++, rightAdv++; }
							if (p6 == 1)rightSelf++;
							else if (p6 == 2)rightAdv++;

							//���ڱ߽�
							if (p1 == 3 || p6 == 3) {
								//��߽�
								if (p1 == 3 && p6 != 3) {
									//������4
									if (rightSelf == 4 && rightAdv == 0)
										setBlock(p1, p2, p3, p4, p5, p6, BLOCK4);
									//���ֳ�4
									if (rightAdv == 4 && rightSelf == 0)
										setBlock(p1, p2, p3, p4, p5, p6, ADVBLOCK4);
									//������3
									if (rightSelf == 3 && rightAdv == 0)
										setBlock(p1, p2, p3, p4, p5, p6, BLOCK3);
									//������3
									if (rightAdv == 3 && rightSelf == 0)
										setBlock(p1, p2, p3, p4, p5, p6, ADVBLOCK3);
									//������2
									if (rightSelf == 2 && rightAdv == 0)
										setBlock(p1, p2, p3, p4, p5, p6, BLOCK2);
									//������2
									if (rightAdv == 2 && rightSelf == 0)
										setBlock(p1, p2, p3, p4, p5, p6, ADVBLOCK2);
								}
								//�ұ߽�
								else if (p1 != 3 && p6 == 3) {
									//������4
									if (leftSelf == 4 && leftAdv == 0)
										setBlock(p1, p2, p3, p4, p5, p6, BLOCK4);
									//���ֳ�4
									if (leftAdv == 4 && leftSelf == 0)
										setBlock(p1, p2, p3, p4, p5, p6, ADVBLOCK4);
									//������3
									if (leftSelf == 3 && leftAdv == 0)
										setBlock(p1, p2, p3, p4, p5, p6, BLOCK3);
									//������3
									if (leftAdv == 3 && leftSelf == 0)
										setBlock(p1, p2, p3, p4, p5, p6, ADVBLOCK3);
									//������2
									if (leftSelf == 2 && leftAdv == 0)
										setBlock(p1, p2, p3, p4, p5, p6, BLOCK2);
									//������2
									if (leftAdv == 2 && leftSelf == 0)
										setBlock(p1, p2, p3, p4, p5, p6, ADVBLOCK2);
								}
							}
							//�ޱ߽�
							else {
								//������4
								if ((leftSelf == 4 && leftAdv == 0) || (rightSelf == 4 && rightAdv == 0))
									setBlock(p1, p2, p3, p4, p5, p6, BLOCK4);
								//���ֳ�4
								if ((leftAdv == 4 && leftSelf == 0) || (rightAdv == 4 && rightSelf == 0))
									setBlock(p1, p2, p3, p4, p5, p6, BLOCK4);
								//������3
								if ((leftSelf == 3 && leftAdv == 0) || (rightSelf == 3 && rightAdv == 0))
									setBlock(p1, p2, p3, p4, p5, p6, BLOCK3);
								//������3
								if ((leftAdv == 3 && leftSelf == 0) || (rightAdv == 3 && rightSelf == 0))
									setBlock(p1, p2, p3, p4, p5, p6, BLOCK3);
								//������2
								if ((leftSelf == 2 && leftAdv == 0) || (rightSelf == 2 && rightAdv == 0))
									setBlock(p1, p2, p3, p4, p5, p6, BLOCK2);
								//������2
								if ((leftAdv == 2 && leftSelf == 0) || (rightAdv == 2 && rightSelf == 0))
									setBlock(p1, p2, p3, p4, p5, p6, BLOCK2);
							}
						}
					}
				}
			}
		}
	}
}

void AI::AIPlay(KEYBOARD board, int &x, int &y) {
	int tmp = this->maxMinSearch(board, DEPTH, INT_MIN, INT_MAX);
	x = this->decision.dPos.x;
	y = this->decision.dPos.y;
}

//��4����3����2
void AI::setBlock(int p1, int p2, int p3, int p4, int p5, int p6, int block) {
	if (this->chessStatus[p1][p2][p3][p4][p5][p6] == 0)
		this->chessStatus[p1][p2][p3][p4][p5][p6] = block;
}

//���̵�����ƥ��
void AI::matchShapeRecord(int **shape, int **board) {
	//��������
	for (int i = 1; i <= SIZE; ++i) {
		for (int j = 0; j < SIZE - 3; ++j) {
			int type = this->chessStatus[board[i][j]][board[i][j + 1]][board[i][j + 2]]
				[board[i][j + 3]][board[i][j + 4]][board[i][j + 5]];
			shape[0][type]++;
		}
	}

	//��������
	for (int i = 0; i < SIZE - 3; ++i) {
		for (int j = 1; j <= SIZE; ++j) {
			int type = this->chessStatus[board[i][j]][board[i + 1][j]][board[i + 2][j]]
				[board[i + 3][j]][board[i + 4][j]][board[i + 5][j]];
			shape[1][type]++;
		}
	}

	//���Խ��߷�������->��������
	for (int i = 0; i < SIZE - 3; ++i) {
		for (int j = 0; j < SIZE - 3; ++j) {
			int type = this->chessStatus[board[i][j]][board[i + 1][j + 1]][board[i + 2]
				[j + 2]][board[i + 3][j + 3]][board[i + 4][j + 4]][board[i + 5][j + 5]];
			shape[2][type]++;
		}
	}

	//���Խ��߷�������->��������
	for (int i = SIZE + 1; i > 4; --i) {
		for (int j = 0; j < SIZE - 3; ++j) {
			int type = this->chessStatus[board[i][j]][board[i - 1][j + 1]][board[i - 2]
				[j + 2]][board[i - 3][j + 3]][board[i - 4][j + 4]][board[i - 5][j + 5]];
			shape[3][type]++;
		}
	}
}

void AI::delete2DArray(int **arr, int row) {
	for (int i = 0; i < row; ++i)
		delete[]arr[i];
	delete[]arr;
}

int AI::evaluation(KEYBOARD board) {
	//�ĸ���������μ�¼��Ӯ���䣬��4����4��17������
	//int shapeRecord[4][17] = {{0}};
	int **shapeRecord = create2DArray(4, 17);

	for (int i = 0; i < 4; ++i) {
		for (int j = 0; j < 17; ++j) {
			shapeRecord[i][j] = 0;
		}
	}

	//��չ���̣�������������ǵ�ɾָ�����ڴ棩
	int **bigBoard = this->extendBoard(board);

	//ƥ������
	this->matchShapeRecord(shapeRecord, bigBoard);

	int score = 0;
	for (int i = 0; i < 17; ++i)
		score += shapeRecord[0][i] * weight[i] + shapeRecord[1][i] * weight[i] +
		shapeRecord[2][i] * weight[i] + shapeRecord[3][i] * weight[i];

	//����ڴ�
	this->delete2DArray(bigBoard, SIZE + 2);
	this->delete2DArray(shapeRecord, 4);
	//delete weight;

	return score;
}

Points AI::localSearch(KEYBOARD board) {
	Points topK{};
	bool localBoard[SIZE][SIZE] = { {false} };
	int weightBoard[SIZE][SIZE] = { {0} };

	//�ҳ����ֲ̾�����ƥ���λ�ã�ƥ�����Ϊ8���������������
	for (int i = 0; i < SIZE; ++i) {
		for (int j = 0; j < SIZE; ++j) {
			//�������ӿ�ʼ��������
			if (board.getSymbolBoard(i, j) == selfFlag || board.getSymbolBoard(i, j) == advFlag) {
				for (int k = -STRIDE; k <= STRIDE; ++k) {
					//����
					if (board.getSymbolBoard(i, j + k) != selfFlag && board.getSymbolBoard(i, j + k) != advFlag &&
						(j + k) < SIZE && (j + k) >= 0)
						localBoard[i][j + k] = true;
					//����
					if (board.getSymbolBoard(i + k, j) != selfFlag && board.getSymbolBoard(i + k, j) != advFlag &&
						(i + k) < SIZE && (i + k) >= 0)
						localBoard[i + k][j] = true;
					//����->����
					if (board.getSymbolBoard(i + k, j + k) != selfFlag && board.getSymbolBoard(i + k, j + k) != advFlag &&
						(i + k) < SIZE && (i + k) >= 0 && (j + k) < SIZE && (j + k) >= 0)
						localBoard[i + k][j + k] = true;
					//����->����
					if (board.getSymbolBoard(i - k, j + k) != selfFlag && board.getSymbolBoard(i - k, j + k) != advFlag &&
						(i - k) < SIZE && (i - k) >= 0 && (j + k) < SIZE && (j + k) >= 0)
						localBoard[i - k][j + k] = true;
				}
			}
		}
	}
	//��weightBoard����Ϊ1ά���飨����10��ѭ����
	//int weightBoard1D[SIZE * SIZE];

	//�ھֲ�������ģ�����ӽ��������ȫ�ֽ��д��
	for (int i = 0; i < SIZE; ++i) {
		for (int j = 0; j < SIZE; ++j) {
			weightBoard[i][j] = INT_MIN;
			if (localBoard[i][j]) {
				//��¼���̵�ǰλ���������ֵ����״��
				int tmpFlag = board.getSymbolBoard(i, j);
				//��������Ϊ1������Ϊ2
				board.setSymbolBoard(i, j, selfFlag);
				weightBoard[i][j] = evaluation(board);
				//weightBoard1D[i*SIZE+j] = weightBoard[i][j] = evaluation(board);
				board.setSymbolBoard(i, j, tmpFlag);
			}
		}
	}

	//ѡ��ǰ10����ֵ�ϴ�ĵ�
	for (int k = 0; k < TOPK; ++k) {
		int tmpMaxWeight = INT_MIN;
		Position tmpPos = Position();
		for (int i = 0; i < SIZE; ++i) {
			for (int j = 0; j < SIZE; ++j) {
				if (tmpMaxWeight < weightBoard[i][j]) {
					tmpMaxWeight = weightBoard[i][j];
					tmpPos.x = i;
					tmpPos.y = j;
				}
			}
		}
		topK.pos[k] = tmpPos;
		topK.score[k] = tmpMaxWeight;
		weightBoard[tmpPos.x][tmpPos.y] = INT_MIN;
	}

	return topK;
}

int AI::maxMinSearch(KEYBOARD board, int depth, int alpha, int beta) {
	//�������Ϊ0�����ط������
	if (depth == 0 || this->isVictory(board)) {
		if (depth == 0) {
			Points topK = this->localSearch(board);
			return topK.score[0];
		}
		else return evaluation(board);
	}
	/*if (depth == 0) {
		Points topK = this->localSearch(board);
		return topK.score[0];
	}*/

	//max��
	else if (depth % 2 == 0) {
		KEYBOARD sameBoard(board);
		Points topK = this->localSearch(board);

		//ģ��ǰ10����λ��
		for (int i = 0; i < TOPK; ++i) {
			int tmpFlag = sameBoard.getSymbolBoard(topK.pos[i].x, topK.pos[i].y);
			sameBoard.setSymbolBoard(topK.pos[i].x, topK.pos[i].y, selfFlag);
			int childAlpha = this->maxMinSearch(sameBoard, depth - 1, alpha, beta);
			sameBoard.setSymbolBoard(topK.pos[i].x, topK.pos[i].y, tmpFlag);
			//alpha��Ϊ�����½磬���ӽڵ��ֵ���ڵ�ǰֵ�������alpha
			if (childAlpha > alpha) {
				alpha = childAlpha;
				if (depth == DEPTH) {
					this->decision.dPos.x = topK.pos[i].x;
					this->decision.dPos.y = topK.pos[i].y;
					this->decision.dScore = topK.score[i];
				}
			}
			//��֦
			if (beta <= alpha)
				break;
		}
		return alpha;
	}

	//min��
	else if (depth % 2 == 1) {
		KEYBOARD invBoard(inverseBoard(board, SIZE, SIZE));
		KEYBOARD sameBoard(board);
		//��������
		Points topK = this->localSearch(invBoard);

		//ģ��ǰ10����λ��
		for (int i = 0; i < TOPK; ++i) {
			int tmpFlag = sameBoard.getSymbolBoard(topK.pos[i].x, topK.pos[i].y);
			sameBoard.setSymbolBoard(topK.pos[i].x, topK.pos[i].y, advFlag);
			int childBeta = this->maxMinSearch(sameBoard, depth - 1, alpha, beta);
			sameBoard.setSymbolBoard(topK.pos[i].x, topK.pos[i].y, tmpFlag);
			//beta��Ϊ�����Ͻ磬���ӽڵ��ֵС�ڵ�ǰֵ�������beta
			if (childBeta < beta) {
				beta = childBeta;
			}
			//��֦
			if (beta <= alpha)
				break;
		}
		return beta;
	}
}

//��չΪ�б߽�Ĵ����̣�����������Ϊ1������Ϊ2���߽�Ϊ3������Ϊ0
int** AI::extendBoard(KEYBOARD board) {
	int **bigBoard = create2DArray(SIZE + 2, SIZE + 2);
	for (int i = 0; i < SIZE + 2; ++i) {
		bigBoard[0][i] = 3;
		bigBoard[i][0] = 3;
		bigBoard[SIZE + 1][i] = 3;
		bigBoard[i][SIZE + 1] = 3;
	}
	for (int i = 0; i < SIZE; ++i) {
		for (int j = 0; j < SIZE; ++j) {
			if (board.getSymbolBoard(i, j) == selfFlag)
				bigBoard[i + 1][j + 1] = 1;
			else if (board.getSymbolBoard(i, j) == advFlag)
				bigBoard[i + 1][j + 1] = 2;
			else
				bigBoard[i + 1][j + 1] = 0;
		}
	}
	return bigBoard;
}

//ʹ��theta���Ƽ����Ϊ�����ͻ��Ƿ�����
//int* AI::setWeight() {
//	int *weight = new int[17];
//	for (int i = 0; i < 17; ++i) {
//		if (i == 0)
//			weight[i] = 0;
//		else if (i > 0 && i < 9)
//			weight[i] = this->weightMode[i - 1];
//		else 
//			weight[i] = -(int)(this->theta * this->weightMode[i - 9]);
//	}
//	
//	return weight;
//}

int** AI::create2DArray(int row, int col) {
	int **arr = new int*[row];
	for (int i = 0; i < row; ++i) {
		arr[i] = new int[col];
	}
	return arr;
}

KEYBOARD AI::inverseBoard(KEYBOARD board, int row, int col) {
	KEYBOARD invBoard(board);
	for (int i = 0; i < row; ++i) {
		for (int j = 0; j < col; ++j) {
			if (invBoard.getSymbolBoard(i, j) == selfFlag)
				invBoard.setSymbolBoard(i, j, advFlag);
			if (invBoard.getSymbolBoard(i, j) == advFlag)
				invBoard.setSymbolBoard(i, j, selfFlag);
		}
	}
	return invBoard;
}

//�жϺ�������ȡʤ
bool AI::isVictory(KEYBOARD board) {
	//WHITE and BLACK
	int flags[2] = { 10, 20 };
	for (auto &flag : flags) {
		for (int i = 2; i < SIZE - 2; ++i) {
			for (int j = 2; j < SIZE - 2; ++j) {
				int flag = 10;
				//ˮƽ����
				if (board.getSymbolBoard(i, j - 1) == flag &&
					board.getSymbolBoard(i, j - 2) == flag &&
					board.getSymbolBoard(i, j + 1) == flag &&
					board.getSymbolBoard(i, j + 2) == flag
					) return true;
				//��ֱ����
				if (board.getSymbolBoard(i - 1, j) == flag &&
					board.getSymbolBoard(i - 2, j) == flag &&
					board.getSymbolBoard(i + 1, j) == flag &&
					board.getSymbolBoard(i + 2, j) == flag
					) return true;
				//���Խ���
				if (board.getSymbolBoard(i - 1, j - 1) == flag &&
					board.getSymbolBoard(i - 2, j - 2) == flag &&
					board.getSymbolBoard(i + 1, j + 1) == flag &&
					board.getSymbolBoard(i + 2, j + 2) == flag
					) return true;
				//���Խ���
				if (board.getSymbolBoard(i - 1, j + 1) == flag &&
					board.getSymbolBoard(i - 2, j + 2) == flag &&
					board.getSymbolBoard(i + 1, j - 1) == flag &&
					board.getSymbolBoard(i + 2, j - 2) == flag
					) return true;
			}
		}
	}
	return false;
}
