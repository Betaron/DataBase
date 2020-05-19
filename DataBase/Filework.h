#pragma once

#include <iostream>
#include "MenuPhrases.h"
#include "Menu.h"
#include <string>
#include <fstream>

class Filework
{
private:
	string DB_name;
	string DB_short_name;
	fstream DB;
	Menu* Builder = new Menu;
public:
	friend const char* phrases::DBmenu_header(string);
	int DB_open(phrases*);
	int DB_create(phrases*);
	int DB_menu(phrases*);

	~Filework() {
		delete Builder;
	}
};

