#include "AI.h"

AI::AI(int selfFlag, int advFlag, float theta) {
	this->selfFlag = selfFlag;
	this->advFlag = advFlag;
	this->theta = theta;
	initChessStatus();
}

void AI::initChessStatus() {
	//己方连5，则赢
	this->chessStatus[0][1][1][1][1][1] = WIN;
	this->chessStatus[1][1][1][1][1][0] = WIN;
	this->chessStatus[2][1][1][1][1][1] = WIN;
	this->chessStatus[1][1][1][1][1][2] = WIN;
	this->chessStatus[3][1][1][1][1][1] = WIN;
	this->chessStatus[1][1][1][1][1][3] = WIN;

	//敌手连5，则输
	this->chessStatus[0][2][2][2][2][2] = LOSE;
	this->chessStatus[2][2][2][2][2][0] = LOSE;
	this->chessStatus[1][2][2][2][2][2] = LOSE;
	this->chessStatus[2][2][2][2][2][1] = LOSE;
	this->chessStatus[3][2][2][2][2][2] = LOSE;
	this->chessStatus[2][2][2][2][2][3] = LOSE;

	//己方活4
	this->chessStatus[0][1][1][1][1][0] = FLEX4;

	//敌手活4
	this->chessStatus[0][2][2][2][2][0] = ADVFLEX4;

	//己方活3
	this->chessStatus[0][1][1][1][0][0] = FLEX3;
	this->chessStatus[0][0][1][1][1][0] = FLEX3;
	this->chessStatus[0][1][0][1][1][0] = FLEX3;
	this->chessStatus[0][1][1][0][1][0] = FLEX3;

	//敌手活3
	this->chessStatus[0][2][2][2][0][0] = ADVFLEX3;
	this->chessStatus[0][0][2][2][2][0] = ADVFLEX3;
	this->chessStatus[0][2][0][2][2][0] = ADVFLEX3;
	this->chessStatus[0][2][2][0][2][0] = ADVFLEX3;

	//己方活2
	this->chessStatus[0][1][1][0][0][0] = FLEX2;
	this->chessStatus[0][1][0][1][0][0] = FLEX2;
	this->chessStatus[0][1][0][0][1][0] = FLEX2;
	this->chessStatus[0][0][1][1][0][0] = FLEX2;
	this->chessStatus[0][0][1][0][1][0] = FLEX2;
	this->chessStatus[0][0][0][1][1][0] = FLEX2;

	//敌手活2
	this->chessStatus[0][2][2][0][0][0] = ADVFLEX2;
	this->chessStatus[0][2][0][2][0][0] = ADVFLEX2;
	this->chessStatus[0][2][0][0][2][0] = ADVFLEX2;
	this->chessStatus[0][0][2][2][0][0] = ADVFLEX2;
	this->chessStatus[0][0][2][0][2][0] = ADVFLEX2;
	this->chessStatus[0][0][0][2][2][0] = ADVFLEX2;

	//己方活1
	this->chessStatus[0][1][0][0][0][0] = FLEX1;
	this->chessStatus[0][0][1][0][0][0] = FLEX1;
	this->chessStatus[0][0][0][1][0][0] = FLEX1;
	this->chessStatus[0][0][0][0][1][0] = FLEX1;

	//敌手活1
	this->chessStatus[0][2][0][0][0][0] = ADVFLEX1;
	this->chessStatus[0][0][2][0][0][0] = ADVFLEX1;
	this->chessStatus[0][0][0][2][0][0] = ADVFLEX1;
	this->chessStatus[0][0][0][0][2][0] = ADVFLEX1;

	//p1-p6分别代表chessStatus中的不同维度，leftSelf左5中的自己棋子个数，leftAdv左5中的敌手棋子个数
	//rightSelf右5中的自己棋子个数，rightAdv右5中的敌手棋子个数
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

							//存在边界
							if (p1 == 3 || p6 == 3) {
								//左边界
								if (p1 == 3 && p6 != 3) {
									//己方冲4
									if (rightSelf == 4 && rightAdv == 0)
										setBlock(p1, p2, p3, p4, p5, p6, BLOCK4);
									//敌手冲4
									if (rightAdv == 4 && rightSelf == 0)
										setBlock(p1, p2, p3, p4, p5, p6, ADVBLOCK4);
									//己方眠3
									if (rightSelf == 3 && rightAdv == 0)
										setBlock(p1, p2, p3, p4, p5, p6, BLOCK3);
									//敌手眠3
									if (rightAdv == 3 && rightSelf == 0)
										setBlock(p1, p2, p3, p4, p5, p6, ADVBLOCK3);
									//己方眠2
									if (rightSelf == 2 && rightAdv == 0)
										setBlock(p1, p2, p3, p4, p5, p6, BLOCK2);
									//敌手眠2
									if (rightAdv == 2 && rightSelf == 0)
										setBlock(p1, p2, p3, p4, p5, p6, ADVBLOCK2);
								}
								//右边界
								else if (p1 != 3 && p6 == 3) {
									//己方冲4
									if (leftSelf == 4 && leftAdv == 0)
										setBlock(p1, p2, p3, p4, p5, p6, BLOCK4);
									//敌手冲4
									if (leftAdv == 4 && leftSelf == 0)
										setBlock(p1, p2, p3, p4, p5, p6, ADVBLOCK4);
									//己方眠3
									if (leftSelf == 3 && leftAdv == 0)
										setBlock(p1, p2, p3, p4, p5, p6, BLOCK3);
									//敌手眠3
									if (leftAdv == 3 && leftSelf == 0)
										setBlock(p1, p2, p3, p4, p5, p6, ADVBLOCK3);
									//己方眠2
									if (leftSelf == 2 && leftAdv == 0)
										setBlock(p1, p2, p3, p4, p5, p6, BLOCK2);
									//敌手眠2
									if (leftAdv == 2 && leftSelf == 0)
										setBlock(p1, p2, p3, p4, p5, p6, ADVBLOCK2);
								}
							}
							//无边界
							else {
								//己方冲4
								if ((leftSelf == 4 && leftAdv == 0) || (rightSelf == 4 && rightAdv == 0))
									setBlock(p1, p2, p3, p4, p5, p6, BLOCK4);
								//对手冲4
								if ((leftAdv == 4 && leftSelf == 0) || (rightAdv == 4 && rightSelf == 0))
									setBlock(p1, p2, p3, p4, p5, p6, BLOCK4);
								//己方眠3
								if ((leftSelf == 3 && leftAdv == 0) || (rightSelf == 3 && rightAdv == 0))
									setBlock(p1, p2, p3, p4, p5, p6, BLOCK3);
								//对手眠3
								if ((leftAdv == 3 && leftSelf == 0) || (rightAdv == 3 && rightSelf == 0))
									setBlock(p1, p2, p3, p4, p5, p6, BLOCK3);
								//己方眠2
								if ((leftSelf == 2 && leftAdv == 0) || (rightSelf == 2 && rightAdv == 0))
									setBlock(p1, p2, p3, p4, p5, p6, BLOCK2);
								//对手眠2
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

//冲4，眠3，眠2
void AI::setBlock(int p1, int p2, int p3, int p4, int p5, int p6, int block) {
	if (this->chessStatus[p1][p2][p3][p4][p5][p6] == 0)
		this->chessStatus[p1][p2][p3][p4][p5][p6] = block;
}

//棋盘的棋形匹配
void AI::matchShapeRecord(int **shape, int **board) {
	//横向棋形
	for (int i = 1; i <= SIZE; ++i) {
		for (int j = 0; j < SIZE - 3; ++j) {
			int type = this->chessStatus[board[i][j]][board[i][j + 1]][board[i][j + 2]]
				[board[i][j + 3]][board[i][j + 4]][board[i][j + 5]];
			shape[0][type]++;
		}
	}

	//竖向棋形
	for (int i = 0; i < SIZE - 3; ++i) {
		for (int j = 1; j <= SIZE; ++j) {
			int type = this->chessStatus[board[i][j]][board[i + 1][j]][board[i + 2][j]]
				[board[i + 3][j]][board[i + 4][j]][board[i + 5][j]];
			shape[1][type]++;
		}
	}

	//主对角线方向，左上->右下棋形
	for (int i = 0; i < SIZE - 3; ++i) {
		for (int j = 0; j < SIZE - 3; ++j) {
			int type = this->chessStatus[board[i][j]][board[i + 1][j + 1]][board[i + 2]
				[j + 2]][board[i + 3][j + 3]][board[i + 4][j + 4]][board[i + 5][j + 5]];
			shape[2][type]++;
		}
	}

	//副对角线方向，左下->右上棋形
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
	//四个方向的棋形记录，赢，输，活4，冲4等17种棋形
	//int shapeRecord[4][17] = {{0}};
	int **shapeRecord = create2DArray(4, 17);

	for (int i = 0; i < 4; ++i) {
		for (int j = 0; j < 17; ++j) {
			shapeRecord[i][j] = 0;
		}
	}

	//扩展棋盘（！！！调用完记得删指针清内存）
	int **bigBoard = this->extendBoard(board);

	//匹配棋形
	this->matchShapeRecord(shapeRecord, bigBoard);

	int score = 0;
	for (int i = 0; i < 17; ++i)
		score += shapeRecord[0][i] * weight[i] + shapeRecord[1][i] * weight[i] +
		shapeRecord[2][i] * weight[i] + shapeRecord[3][i] * weight[i];

	//清空内存
	this->delete2DArray(bigBoard, SIZE + 2);
	this->delete2DArray(shapeRecord, 4);
	//delete weight;

	return score;
}

Points AI::localSearch(KEYBOARD board) {
	Points topK{};
	bool localBoard[SIZE][SIZE] = { {false} };
	int weightBoard[SIZE][SIZE] = { {0} };

	//找出棋盘局部搜索匹配的位置，匹配规则为8个方向的三格延伸
	for (int i = 0; i < SIZE; ++i) {
		for (int j = 0; j < SIZE; ++j) {
			//己方棋子开始进行搜索
			if (board.getSymbolBoard(i, j) == selfFlag || board.getSymbolBoard(i, j) == advFlag) {
				for (int k = -STRIDE; k <= STRIDE; ++k) {
					//横向
					if (board.getSymbolBoard(i, j + k) != selfFlag && board.getSymbolBoard(i, j + k) != advFlag &&
						(j + k) < SIZE && (j + k) >= 0)
						localBoard[i][j + k] = true;
					//纵向
					if (board.getSymbolBoard(i + k, j) != selfFlag && board.getSymbolBoard(i + k, j) != advFlag &&
						(i + k) < SIZE && (i + k) >= 0)
						localBoard[i + k][j] = true;
					//左上->右下
					if (board.getSymbolBoard(i + k, j + k) != selfFlag && board.getSymbolBoard(i + k, j + k) != advFlag &&
						(i + k) < SIZE && (i + k) >= 0 && (j + k) < SIZE && (j + k) >= 0)
						localBoard[i + k][j + k] = true;
					//左下->右上
					if (board.getSymbolBoard(i - k, j + k) != selfFlag && board.getSymbolBoard(i - k, j + k) != advFlag &&
						(i - k) < SIZE && (i - k) >= 0 && (j + k) < SIZE && (j + k) >= 0)
						localBoard[i - k][j + k] = true;
				}
			}
		}
	}
	//将weightBoard拉伸为1维数组（避免10次循环）
	//int weightBoard1D[SIZE * SIZE];

	//在局部搜索后模拟落子结果对棋盘全局进行打分
	for (int i = 0; i < SIZE; ++i) {
		for (int j = 0; j < SIZE; ++j) {
			weightBoard[i][j] = INT_MIN;
			if (localBoard[i][j]) {
				//记录棋盘当前位置所代表的值（形状）
				int tmpFlag = board.getSymbolBoard(i, j);
				//己方棋子为1，敌手为2
				board.setSymbolBoard(i, j, selfFlag);
				weightBoard[i][j] = evaluation(board);
				//weightBoard1D[i*SIZE+j] = weightBoard[i][j] = evaluation(board);
				board.setSymbolBoard(i, j, tmpFlag);
			}
		}
	}

	//选择前10个分值较大的点
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
	//迭代深度为0，返回分析结果
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

	//max层
	else if (depth % 2 == 0) {
		KEYBOARD sameBoard(board);
		Points topK = this->localSearch(board);

		//模拟前10落子位置
		for (int i = 0; i < TOPK; ++i) {
			int tmpFlag = sameBoard.getSymbolBoard(topK.pos[i].x, topK.pos[i].y);
			sameBoard.setSymbolBoard(topK.pos[i].x, topK.pos[i].y, selfFlag);
			int childAlpha = this->maxMinSearch(sameBoard, depth - 1, alpha, beta);
			sameBoard.setSymbolBoard(topK.pos[i].x, topK.pos[i].y, tmpFlag);
			//alpha作为己方下界，若子节点的值大于当前值，则更新alpha
			if (childAlpha > alpha) {
				alpha = childAlpha;
				if (depth == DEPTH) {
					this->decision.dPos.x = topK.pos[i].x;
					this->decision.dPos.y = topK.pos[i].y;
					this->decision.dScore = topK.score[i];
				}
			}
			//剪枝
			if (beta <= alpha)
				break;
		}
		return alpha;
	}

	//min层
	else if (depth % 2 == 1) {
		KEYBOARD invBoard(inverseBoard(board, SIZE, SIZE));
		KEYBOARD sameBoard(board);
		//敌手下棋
		Points topK = this->localSearch(invBoard);

		//模拟前10落子位置
		for (int i = 0; i < TOPK; ++i) {
			int tmpFlag = sameBoard.getSymbolBoard(topK.pos[i].x, topK.pos[i].y);
			sameBoard.setSymbolBoard(topK.pos[i].x, topK.pos[i].y, advFlag);
			int childBeta = this->maxMinSearch(sameBoard, depth - 1, alpha, beta);
			sameBoard.setSymbolBoard(topK.pos[i].x, topK.pos[i].y, tmpFlag);
			//beta作为敌手上界，若子节点的值小于当前值，则更新beta
			if (childBeta < beta) {
				beta = childBeta;
			}
			//剪枝
			if (beta <= alpha)
				break;
		}
		return beta;
	}
}

//扩展为有边界的大棋盘，己方棋子设为1，敌手为2，边界为3，其他为0
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

//使用theta控制计算机为进攻型还是防守型
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

//判断黑棋或白棋取胜
bool AI::isVictory(KEYBOARD board) {
	//WHITE and BLACK
	int flags[2] = { 10, 20 };
	for (auto &flag : flags) {
		for (int i = 2; i < SIZE - 2; ++i) {
			for (int j = 2; j < SIZE - 2; ++j) {
				int flag = 10;
				//水平方向
				if (board.getSymbolBoard(i, j - 1) == flag &&
					board.getSymbolBoard(i, j - 2) == flag &&
					board.getSymbolBoard(i, j + 1) == flag &&
					board.getSymbolBoard(i, j + 2) == flag
					) return true;
				//竖直方向
				if (board.getSymbolBoard(i - 1, j) == flag &&
					board.getSymbolBoard(i - 2, j) == flag &&
					board.getSymbolBoard(i + 1, j) == flag &&
					board.getSymbolBoard(i + 2, j) == flag
					) return true;
				//主对角线
				if (board.getSymbolBoard(i - 1, j - 1) == flag &&
					board.getSymbolBoard(i - 2, j - 2) == flag &&
					board.getSymbolBoard(i + 1, j + 1) == flag &&
					board.getSymbolBoard(i + 2, j + 2) == flag
					) return true;
				//副对角线
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
