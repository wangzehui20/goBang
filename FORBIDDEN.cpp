#define MMIN(x,y) x < y ? x : y

#include "forbidden.h"
#include <iostream>

using namespace std;

FORBIDDEN::FORBIDDEN(int **board, int row, int col) {
	this->board = board;
	//相当于SIZE-1
	this->row = row - 1;
	this->col = col - 1;
}

FORBIDDEN::~FORBIDDEN() {
	for (int i = 0; i < row + 1; ++i)
		delete[]board[i];
	delete[]board;
}

bool FORBIDDEN::isForbidden(int x, int y) {
	this->x = x;
	this->y = y;

	if (huosan() >= 2)
	{
		cout << "双活三禁手！黑棋负！" << endl;
		return true;
	}
	if (si() >= 2)
	{
		cout << "双四禁手！黑棋负！" << endl;
		return true;
	}
	if (liu() > 0)
	{
		cout << "长连禁手！黑棋负！" << endl;
		return true;
	}

	return false;
}

int FORBIDDEN::huosan() {
	//横活三
	int henghuo3 = 0;
	int i = 0;
	int j = 0;
	for (j = 0; j <= col - 5; j++)
	{
		if (board[x][j] == 0 && board[x][j + 5] == 0)
		{
			if (board[x][j + 1] == 1 && board[x][j + 2] == 1 && board[x][j + 3] == 1 &&
				board[x][j + 4] == 0 && (y == j + 1 || y == j + 2 || y == j + 3))
			{
				henghuo3 = 1;
			}

			if (board[x][j + 1] == 1 && board[x][j + 2] == 1 && board[x][j + 4] == 1 &&
				board[x][j + 3] == 0 && (y == j + 1 || y == j + 2 || y == j + 4))
			{
				henghuo3 = 1;
			}

			if (board[x][j + 1] == 1 && board[x][j + 3] == 1 && board[x][j + 4] == 1 &&
				board[x][j + 2] == 0 && (y == j + 1 || y == j + 3 || y == j + 4))
			{
				henghuo3 = 1;
			}

			if (board[x][j + 2] == 1 && board[x][j + 3] == 1 && board[x][j + 4] == 1 &&
				board[x][j + 1] == 0 && (y == j + 2 || y == j + 3 || y == j + 4))
			{
				henghuo3 = 1;
			}
		}
	}

	//竖活三
	int shuhuo3 = 0;
	i = 0;
	j = 0;
	for (i = 0; i <= row - 5; i++)
	{
		if (board[i][y] == 0 && board[i + 5][y] == 0)
		{
			if (board[i + 1][y] == 1 && board[i + 2][y] == 1 && board[i + 3][y] == 1 &&
				board[i + 4][y] == 0 && (x == i + 1 || x == i + 2 || x == i + 3))
			{
				shuhuo3 = 1;
			}

			if (board[i + 1][y] == 1 && board[i + 2][y] == 1 && board[i + 4][y] == 1 &&
				board[i + 3][y] == 0 && (x == i + 1 || x == i + 2 || x == i + 4))
			{
				shuhuo3 = 1;
			}

			if (board[i + 1][y] == 1 && board[i + 3][y] == 1 && board[i + 4][y] == 1 &&
				board[i + 2][y] == 0 && (x == i + 1 || x == i + 3 || x == i + 4))
			{
				shuhuo3 = 1;
			}

			if (board[i + 2][y] == 1 && board[i + 3][y] == 1 && board[i + 4][y] == 1 &&
				board[i + 1][y] == 0 && (x == i + 2 || x == i + 3 || x == i + 4))
			{
				shuhuo3 = 1;
			}
		}
	}

	//左斜活3
	int zuoxiehuo3 = 0;
	i = x - MMIN(x, y);
	j = y - MMIN(x, y);
	while (i <= row - 5 && j <= col - 5)
	{
		if (board[i, j] == 0 && board[i + 5, j + 5] == 0)
		{
			if (board[i + 1][j + 1] == 1 && board[i + 2][j + 2] == 1 && board[i + 3][j + 3] == 1 &&
				board[i + 4][j + 4] == 0 &&
				(x == i + 1 && y == j + 1 || x == i + 2 && y == j + 2 || x == i + 3 && y == j + 3))
			{
				zuoxiehuo3 = 1;
			}

			if (board[i + 1][j + 1] == 1 && board[i + 2][j + 2] == 1 && board[i + 4][j + 4] == 1 &&
				board[i + 3][j + 3] == 0 &&
				(x == i + 1 && y == j + 1 || x == i + 2 && y == j + 2 || x == i + 4 && y == j + 4))
			{
				zuoxiehuo3 = 1;
			}

			if (board[i + 1][j + 1] == 1 && board[i + 3][j + 3] == 1 && board[i + 4][j + 4] == 1 &&
				board[i + 2][j + 2] == 0 &&
				(x == i + 1 && y == j + 1 || x == i + 3 && y == j + 3 || x == i + 4 && y == j + 4))
			{
				zuoxiehuo3 = 1;
			}

			if (board[i + 2][j + 2] == 1 && board[i + 3][j + 3] == 1 && board[i + 4][j + 4] == 1 &&
				board[i + 1][j + 1] == 0 &&
				(x == i + 2 && y == j + 2 || x == i + 3 && y == j + 3 || x == i + 4 && y == j + 4))
			{
				zuoxiehuo3 = 1;
			}
		}

		i++;
		j++;
	}

	//右斜活3
	int youxiehuo3 = 0;
	i = x - MMIN(x, row - y);
	j = y + MMIN(x, col - y);
	while (i <= row - 5 && j >= 5)
	{
		if (board[i, j] == 0 && board[i + 5, j - 5] == 0)
		{
			if (board[i + 1][j - 1] == 1 && board[i + 2][j - 2] == 1 && board[i + 3][j - 3] == 1 &&
				board[i + 4][j - 4] == 0 &&
				(x == i + 1 && y == j - 1 || x == i + 2 && y == j - 2 || x == i + 3 && y == j - 3))
			{
				youxiehuo3 = 1;
			}

			if (board[i + 1][j - 1] == 1 && board[i + 2][j - 2] == 1 && board[i + 4][j - 4] == 1 &&
				board[i + 3][j - 3] == 0 &&
				(x == i + 1 && y == j - 1 || x == i + 2 && y == j - 2 || x == i + 4 && y == j - 4))
			{
				youxiehuo3 = 1;
			}

			if (board[i + 1][j - 1] == 1 && board[i + 3][j - 3] == 1 && board[i + 4][j - 4] == 1 &&
				board[i + 2][j - 2] == 0 &&
				(x == i + 1 && y == j - 1 || x == i + 3 && y == j - 3 || x == i + 4 && y == j - 4))
			{
				youxiehuo3 = 1;
			}

			if (board[i + 2][j - 2] == 1 && board[i + 3][j - 3] == 1 && board[i + 4][j - 4] == 1 &&
				board[i + 1][j - 1] == 0 &&
				(x == i + 2 && y == j - 2 || x == i + 3 && y == j - 3 || x == i + 4 && y == j - 4))
			{
				youxiehuo3 = 1;
			}
		}

		i++;
		j--;
	}
	if (t == 5)
		cout << henghuo3 << shuhuo3 << zuoxiehuo3 << youxiehuo3;
	t++;
	return henghuo3 + shuhuo3 + zuoxiehuo3 + youxiehuo3;
}

int FORBIDDEN::si() {
	//横4
	int heng4 = 0;
	int i = 0;
	int j = 0;
	for (j = 0; j <= col - 4; j++)
	{
		if (y == j || y == j + 1 || y == j + 2 || y == j + 3 || y == j + 4)
		{
			if (board[x][j] == 1 && board[x][j + 1] == 1 &&
				board[x][j + 2] == 1 && board[x][j + 3] == 1)
			{
				heng4 = 1;
			}

			if (board[x][j] == 1 &&
				board[x][j + 1] == 0 && board[x][j + 2] == 1 &&
				board[x][j + 3] == 1 && board[x][j + 4] == 1)
			{
				heng4 = 1;
			}

			if (board[x][j] == 1 &&
				board[x][j + 1] == 1 && board[x][j + 2] == 0 &&
				board[x][j + 3] == 1 && board[x][j + 4] == 1)
			{
				heng4 = 1;
			}

			if (board[x][j] == 1 &&
				board[x][j + 1] == 1 && board[x][j + 2] == 1 &&
				board[x][j + 3] == 0 && board[x][j + 4] == 1)
			{
				heng4 = 1;
			}

			if (board[x][j + 1] == 1 && board[x][j + 2] == 1 &&
				board[x][j + 3] == 1 && board[x][j + 4] == 1)
			{
				heng4 = 1;
			}
		}
	}

	//竖四
	int shu4 = 0;
	i = 0;
	j = 0;
	for (i = 0; i <= row - 4; i++)
	{
		if (x == i || x == i + 1 || x == i + 2 || x == i + 3 || x == i + 4)
		{
			if (board[i][y] == 1 && board[i + 1][y] == 1 &&
				board[i + 2][y] == 1 && board[i + 3][y] == 1)
			{
				shu4 = 1;
			}

			if (board[i][y] == 1 &&
				board[i + 1][y] == 0 && board[i + 2][y] == 1 &&
				board[i + 3][y] == 1 && board[i + 4][y] == 1)
			{
				shu4 = 1;
			}

			if (board[i][y] == 1 &&
				board[i + 1][y] == 1 && board[i + 2][y] == 0 &&
				board[i + 3][y] == 1 && board[i + 4][y] == 1)
			{
				shu4 = 1;
			}

			if (board[i][y] == 1 &&
				board[i + 1][y] == 1 && board[i + 2][y] == 1 &&
				board[i + 3][y] == 0 && board[i + 4][y] == 1)
			{
				shu4 = 1;
			}

			if (board[i + 1][y] == 1 && board[i + 2][y] == 1 &&
				board[i + 3][y] == 1 && board[i + 4][y] == 1)
			{
				shu4 = 1;
			}
		}
	}

	//左斜四
	int zuoxie4 = 0;
	i = x - MMIN(x, y);
	j = y - MMIN(x, y);
	while (i <= row - 4 && j <= col - 4)
	{
		if (x == i && y == j || x == i + 1 && y == j + 1 || x == i + 2 && y == j + 2 ||
			x == i + 3 && y == j + 3 || x == i + 4 && y == j + 4)
		{
			if (board[i][j] == 1 && board[i + 1][j + 1] == 1 &&
				board[i + 2][j + 2] == 1 && board[i + 3][j + 3] == 1)
			{
				zuoxie4 = 1;
			}

			if (board[i][j] == 1 &&
				board[i + 1][j + 1] == 0 && board[i + 2][j + 2] == 1 &&
				board[i + 3][j + 3] == 1 && board[i + 4][j + 4] == 1)
			{
				zuoxie4 = 1;
			}

			if (board[i][j] == 1 &&
				board[i + 1][j + 1] == 1 && board[i + 2][j + 2] == 0 &&
				board[i + 3][j + 3] == 1 && board[i + 4][j + 4] == 1)
			{
				zuoxie4 = 1;
			}

			if (board[i][j] == 1 &&
				board[i + 1][j + 1] == 1 && board[i + 2][j + 2] == 1 &&
				board[i + 3][j + 3] == 0 && board[i + 4][j + 4] == 1)
			{
				zuoxie4 = 1;
			}

			if (board[i + 1][j + 1] == 1 && board[i + 2][j + 2] == 1 &&
				board[i + 3][j + 3] == 1 && board[i + 4][j + 4] == 1)
			{
				zuoxie4 = 1;
			}
		}

		i++;
		j++;
	}

	//右斜四
	int youxie4 = 0;
	i = x - MMIN(x, row - y);
	j = y + MMIN(x, col - y);
	while (i <= row - 4 && j >= 4)
	{
		if (x == i && y == j || x == i + 1 && y == j - 1 || x == i + 2 && y == j - 2 || x == i + 3 && y == j - 3 || x == i + 4 && y == j - 4)
		{
			if (board[i][j] == 1 && board[i + 1][j - 1] == 1 &&
				board[i + 2][j - 2] == 1 && board[i + 3][j - 3] == 1)
			{
				youxie4 = 1;
			}

			if (board[i][j] == 1 &&
				board[i + 1][j - 1] == 0 && board[i + 2][j - 2] == 1 &&
				board[i + 3][j - 3] == 1 && board[i + 4][j - 4] == 1)
			{
				youxie4 = 1;
			}

			if (board[i][j] == 1 &&
				board[i + 1][j - 1] == 1 && board[i + 2][j - 2] == 0 &&
				board[i + 3][j - 3] == 1 && board[i + 4][j - 4] == 1)
			{
				youxie4 = 1;
			}

			if (board[i][j] == 1 &&
				board[i + 1][j - 1] == 1 && board[i + 2][j - 2] == 1 &&
				board[i + 3][j - 3] == 0 && board[i + 4][j - 4] == 1)
			{
				youxie4 = 1;
			}

			if (board[i + 1][j - 1] == 1 && board[i + 2][j - 2] == 1 &&
				board[i + 3][j - 3] == 1 && board[i + 4][j - 4] == 1)
			{
				youxie4 = 1;
			}
		}

		i++;
		j--;
	}

	return heng4 + shu4 + zuoxie4 + youxie4;
}

int FORBIDDEN::liu() {
	//横六连
	int heng6 = 0;
	int i = 0;
	int j = 0;
	for (j = 0; j <= col - 5; j++)
	{
		if (y == j || y == j + 1 || y == j + 2 || y == j + 3 || y == j + 4 || y == j + 5)
		{
			if (board[x][j] == 1 && board[x][j + 1] == 1 &&
				board[x][j + 2] == 1 && board[x][j + 3] == 1 &&
				board[x][j + 4] == 1 && board[x][j + 5] == 1)
			{
				heng6 = 1;
			}
		}
	}

	//竖六连
	int shu6 = 0;
	i = 0;
	j = 0;
	for (i = 0; i <= row - 5; i++)
	{
		if (x == i || x == i + 1 || x == i + 2 || x == i + 3 || x == i + 4 || x == i + 5)
		{
			if (board[i][y] == 1 && board[i + 1][y] == 1 &&
				board[i + 2][y] == 1 && board[i + 3][y] == 1 &&
				board[i + 4][y] == 1 && board[i + 5][y] == 1)
			{
				shu6 = 1;
			}
		}
	}

	//左斜六
	int zuoxie6 = 0;
	i = x - MMIN(x, y);
	j = y - MMIN(x, y);
	while (i <= row - 5 && j <= col - 5)
	{
		if (x == i && y == j || x == i + 1 && y == j + 1 || x == i + 2 && y == j + 2 ||
			x == i + 3 && y == j + 3 || x == i + 4 && y == j + 4 || x == i + 5 && y == j + 5)
		{
			if (board[i][j] == 1 && board[i + 1][j + 1] == 1 &&
				board[i + 2][j + 2] == 1 && board[i + 3][j + 3] == 1 &&
				board[i + 4][j + 4] == 1 && board[i + 5][j + 5] == 1)
			{
				zuoxie6 = 1;
			}
		}

		i++;
		j++;
	}

	//右斜六
	int youxie6 = 0;
	i = x - MMIN(x, row - y);
	j = y + MMIN(x, col - y);
	while (i <= row - 5 && j >= 5)
	{
		if (x == i && y == j || x == i + 1 && y == j + 1 || x == i + 2 && y == j + 2 ||
			x == i + 3 && y == j + 3 || x == i + 4 && y == j + 4 || x == i + 5 && y == j + 5)
		{
			if (board[i][j] == 1 && board[i + 1][j - 1] == 1 &&
				board[i + 2][j - 2] == 1 && board[i + 3][j - 3] == 1 &&
				board[i + 4][j - 4] == 1 && board[i + 5][j - 5] == 1)
			{
				youxie6 = 1;
			}
		}

		i++;
		j--;
	}

	return heng6 + shu6 + zuoxie6 + youxie6;
}