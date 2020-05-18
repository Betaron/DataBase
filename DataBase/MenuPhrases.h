#pragma once

#define NaN return "NaN"

using namespace	std;

class phrases {
public:
	virtual const char* MainMenu_header() { NaN; }
	virtual const char* MainMenu_footer() { NaN; }
	virtual const char* CreateDB() { NaN; }
	virtual const char* LoadDB() { NaN; }
	virtual const char* LengSet() { NaN; }
	virtual const char* Exit() { NaN; }
	virtual const char* LangSet_header() { NaN; }
	virtual const char* Lang_eng() { NaN; }
	virtual const char* Lang_rus() { NaN; }
	virtual const char* DBname_ivite() { NaN; }
	virtual const char* GoMM() { NaN; }
};

class rus: public phrases{
public:
	const char* MainMenu_header() { return "Главное меню"; }
	const char* MainMenu_footer() { return "Для перемещения используйте стрелки\n'Enter', чтобы выбрать"; }
	const char* CreateDB() { return "Создать базу данных"; }
	const char* LoadDB() { return "Загрузить базу данных"; }
	const char* LengSet() { return "Выбрать язык"; }
	const char* Exit() { return "Выход"; }
	const char* Lang_eng() { return "Английский"; }
	const char* Lang_rus() { return "Русский"; }
	const char* DBname_ivite() { return "Введите название базы данных"; }
	const char* GoMM() { return "Выйти в главное меню"; }

};

class eng: public phrases {
public:
	const char* MainMenu_header() { return "Main menu"; }
	const char* MainMenu_footer() { return "Use arrows to move\n'Enter' to choose*"; }
	const char* CreateDB() { return "Create a data base"; }
	const char* LoadDB() { return "Load a data base"; }
	const char* LengSet() { return "Select language"; }
	const char* Exit() { return "Exit"; }
	const char* Lang_eng() { return  "English"; }
	const char* Lang_rus() { return  "Russian"; }
	const char* DBname_ivite() { return "Enter data base name"; }
	const char* GoMM() { return "Go to main menu"; }
};