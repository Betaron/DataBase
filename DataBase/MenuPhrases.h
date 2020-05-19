#pragma once

#define NaN return "NaN"

using namespace	std;

class phrases {
protected:
	string str;
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
	virtual const char* Ftry() { NaN; }
	virtual const char* Fope() { NaN; }
	virtual const char* Ferr() { NaN; }
	virtual const char* Femp() { NaN; }
	virtual const char* FnDB() { NaN; }
	virtual const char* FceateErr() { NaN; }
	virtual const char* DBmenu_header(string) { NaN; }
	virtual const char* ShowDB() { NaN; }
	virtual const char* AddEntry() { NaN; }
	virtual const char* Task44() { NaN; }
	virtual const char* DBmenu_footer() { NaN; }
};

class rus: public phrases{
public:
	const char* MainMenu_header() { return "������� ����"; }
	const char* MainMenu_footer() { return "��� ����������� ����������� �������.'Enter', ����� �������\n��� ������ ��������� ����� ������� '!Q'"; }
	const char* CreateDB() { return "������� ���� ������"; }
	const char* LoadDB() { return "��������� ���� ������"; }
	const char* LengSet() { return "������� ����"; }
	const char* Exit() { return "�����"; }
	const char* Lang_eng() { return "����������"; }
	const char* Lang_rus() { return "�������"; }
	const char* DBname_ivite() { return "������� �������� ���� ������"; }
	const char* GoMM() { return "����� � ������� ����"; }
	const char* Ftry() { return "������� ������� ����..."; }
	const char* Fope() { return "���� ������"; }
	const char* Ferr() { return "������! ���������� �����"; }
	const char* Femp() { return "���� ����. �������� ������"; }
	const char* FnDB() { return "���� - �� ���� ������. �������� ������"; }
	const char* FceateErr() { return "���� � ����� ������ ����������. �������� �����"; }
	const char* DBmenu_header(string  DBname) { 
		this->str = "���� ������: " + DBname;
		return this->str.c_str();
	}
	const char* ShowDB() { return "�������� ���� ������"; }
	const char* AddEntry() { return "�������� ����� ������"; }
	virtual const char* Task44() { return "������� �������� - 44"; }
	virtual const char* DBmenu_footer() {
		return "��� �������������� ��� �������� �����������:\n'�������� ���� ������'.\n��� ���������� ������� �������� � ������";
	}
};

class eng: public phrases {
public:
	const char* MainMenu_header() { return "Main menu"; }
	const char* MainMenu_footer() { return "Use arrows to move. 'Enter' to choose\nTo cancel input state enter '!Q'"; }
	const char* CreateDB() { return "Create a database"; }
	const char* LoadDB() { return "Load a database"; }
	const char* LengSet() { return "Select language"; }
	const char* Exit() { return "Exit"; }
	const char* Lang_eng() { return  "English"; }
	const char* Lang_rus() { return  "Russian"; }
	const char* DBname_ivite() { return "Enter database name"; }
	const char* GoMM() { return "Go to main menu"; }
	const char* Ftry() { return "Trying to open file..."; }
	const char* Fope() { return "File open"; }
	const char* Ferr() { return "Error! Try again"; }
	const char* Femp() { return "The file is empty. Choose another"; }
	const char* FnDB() { return "The file - not a database. Choose another"; }
	const char* FceateErr() { return "A file with the same name exists. Try again"; }
	const char* DBmenu_header(string DBname) {
		this->str = "Database: " + DBname;
		return this->str.c_str();
	}
	const char* ShowDB() { return "Show database"; }
	const char* AddEntry() { return "Add New Entry"; }
	virtual const char* Task44() { return "Task of variant - 44"; }
	virtual const char* DBmenu_footer() {
		return "To edit or delete use:\n'Show database'.\nYou must select a student in the list.";
	}
};