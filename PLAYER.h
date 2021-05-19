#pragma once
#include <string>

using namespace std;

class PLAYER {
public:
	int row;        //ÐÐ
	int col;        //ÁÐ
	int flag;
	string role;
	PLAYER(string role, int flag);
	~PLAYER();
};