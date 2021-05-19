#pragma once

class FORBIDDEN {
private:
	int **board;
	int x, y;
	int row, col;
	int t = 1;
public:
	FORBIDDEN(int **board, int row, int col);
	~FORBIDDEN();
	bool isForbidden(int x, int y);
	int huosan();
	int si();
	int liu();
};