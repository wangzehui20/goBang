#pragma once
#include <string>

using namespace std;

class PLAYER {
public:
	int row;        //��
	int col;        //��
	int flag;
	string role;
	PLAYER(string role, int flag);
	~PLAYER();
};