#pragma once
#include <iostream>
#include <conio.h>
#include <Windows.h>

using namespace std;

#define UP 80
#define DOWN 72
#define ENTER 13

class Menu {

private:
	uint16_t cursor;
public:
	Menu() {
		cursor = 0;
	}
	int MenuCreate(size_t len, string m ...) {
		cursor = 0;
		string* ptr = &m;
		do {
			system("cls");
			for (uint16_t i = 0; i < len; i++) {
				if (i == cursor) cout << " > ";
				cout << *(ptr+i) << endl;
			}
			switch (_getch())
			{
			case UP:
				if (cursor < len - 1) cursor++;
				break;
			case DOWN:
				if (cursor > 0) cursor--;
				break;
			case ENTER:
				return cursor;
			default:
				break;
			}
		} while (1);
	}
};