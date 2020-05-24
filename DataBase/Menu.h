#pragma once
#include <iostream>
#include <conio.h>

using namespace std;

#define UP 80
#define DOWN 72
#define ENTER 13

class Menu {
public:
	int MenuCreate(const char* header, const char* footer, int len, const char* m ...) {
		int cursor(0);
		uint8_t f = 1;
		const char** ptr = &m;
		do {
			system("cls");
			cout << header << endl << endl;
			for (uint16_t i = 0; i < len; i++) {
				if (i == cursor) cout << " > ";
				cout << ptr[i] << endl;
			}
			cout << endl << footer << endl;

			switch (_getch())
			{
			case UP:
				if (cursor < len - 1) cursor++;
				break;
			case DOWN:
				if (cursor > 0) cursor--;
				break;
			case ENTER:
				system("cls");
				return cursor;
			default:
				break;
			}
		} while (1);
	}
};