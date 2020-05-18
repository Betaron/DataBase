#pragma once
#include <string>

#define NaN return "NaN"

using namespace	std;

class phrases {
public:
	virtual string MainMenu_header() { NaN; }
	virtual string MainMenu_footer() { NaN; }
	virtual string CreateDB() { NaN; }
	virtual string LoadDB() { NaN; }
	virtual string LengSet() { NaN; }
	virtual string Exit() { NaN; }
};

class rus: public phrases{
public:
	string MainMenu_header() { return "Главное меню"; }
	string MainMenu_footer() { return "Для перемещения используйте стрелки*"; }
	string CreateDB() { return "Создать базу данных"; }
	string LoadDB() { return "Загрузить базу данных"; }
	string LengSet() { return "Выбрать язык"; }
	string Exit() { return "Выход"; }
};

class eng: public phrases {
public:
	string MainMenu_header() { return "Main menu"; }
	string MainMenu_footer() { return "Use arrows to move*"; }
	string CreateDB() { return "Create a data base"; }
	string LoadDB() { return "Load a data base"; }
	string LengSet() { return "Select language"; }
	string Exit() { return "Exit"; }
};