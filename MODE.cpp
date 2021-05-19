#include "MODE.h"
#include <iostream>
#include <windows.h>

using namespace std;

int MODE::chooseMode() {
	//clean screen
	system("cls");
	cout << "**********************************************************" << endl;
	cout << "******************0.Exit**********************************" << endl;
	cout << "******************1.Player vs Player**********************" << endl;
	cout << "******************2.Player vs Computer********************" << endl;
	cout << "******************3.Computer vs Computer******************" << endl;
	cout << "**********************************************************" << endl;

	while (true) {
		int choice;
		cout << "please choose mode : ";
		cin >> choice;
		if (choice == 0)
			exit(1);
		else if (choice == 1 || choice == 2 || choice == 3)
			return choice;
		else
			cout << "input is invalid, please input again !" << endl;
	}
}

bool MODE::chooseChildMode() {
	system("cls");
	cout << "mode 1 : player first " << endl << "mode 2 : computer first" << endl;
	while (true) {
		printf("which mode do you want to choose, 1 or 2 ? \nchoosemode is : ");
		int mode;
		cin >> mode;
		if (mode == 1)return false;
		else if (mode == 2)return true;
		else
			cout << "mode is invalid, please input again !" << endl;
	}
}

void MODE::setConsoleColor() {
	//设置控制台背景为淡黄色
	HANDLE outHandle = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(outHandle, 0x0e);
}