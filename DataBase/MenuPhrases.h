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
	virtual string LangSet_header() { NaN; }
	virtual string Lang_eng() { NaN; }
	virtual string Lang_rus() { NaN; }
};

class rus: public phrases{
public:
	string MainMenu_header() { return "������� ����"; }
	string MainMenu_footer() { return "��� ����������� ����������� �������\n'Enter', ����� �������"; }
	string CreateDB() { return "������� ���� ������"; }
	string LoadDB() { return "��������� ���� ������"; }
	string LengSet() { return "������� ����"; }
	string Exit() { return "�����"; }

	string Lang_eng() { return "����������"; }
	string Lang_rus() { return "�������"; }

};

class eng: public phrases {
public:
	string MainMenu_header() { return "Main menu"; }
	string MainMenu_footer() { return "Use arrows to move\n'Enter' to choose*"; }
	string CreateDB() { return "Create a data base"; }
	string LoadDB() { return "Load a data base"; }
	string LengSet() { return "Select language"; }
	string Exit() { return "Exit"; }

	string Lang_eng() { return  "English"; }
	string Lang_rus() { return  "Russian"; }
};