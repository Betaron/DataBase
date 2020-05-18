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
	const char* MainMenu_header() { return "������� ����"; }
	const char* MainMenu_footer() { return "��� ����������� ����������� �������\n'Enter', ����� �������"; }
	const char* CreateDB() { return "������� ���� ������"; }
	const char* LoadDB() { return "��������� ���� ������"; }
	const char* LengSet() { return "������� ����"; }
	const char* Exit() { return "�����"; }
	const char* Lang_eng() { return "����������"; }
	const char* Lang_rus() { return "�������"; }
	const char* DBname_ivite() { return "������� �������� ���� ������"; }
	const char* GoMM() { return "����� � ������� ����"; }

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