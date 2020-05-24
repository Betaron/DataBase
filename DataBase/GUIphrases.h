#pragma once

#include "Windows.h"
#include <string>
#define NaN return "NaN"

using namespace	std;

class phrases {
protected:
	string str;
public:
	phrases() {
		SetConsoleCP(1251);
		SetConsoleOutputCP(1251);
	}
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

	virtual const char* Student_header(string, string, string, string, string) { NaN; }
	virtual const char* Name() { NaN; }
	virtual const char* Surname() { NaN; }
	virtual const char* MidName() { NaN; }
	virtual const char* Gender() { NaN; }
	virtual const char* Gender(int16_t) { NaN; }
	virtual const char* Birth() { NaN; }
	virtual const char* UniYear() { NaN; }
	virtual const char* Faculty() { NaN; }
	virtual const char* Departament() { NaN; }
	virtual const char* Group() { NaN; }
	virtual const char* GrBookNum() { NaN; }
	virtual const char* GoEnterGr() { NaN; }
	virtual const char* DEL_stud() { NaN; }
	virtual const char* GoDBmenu() { NaN; }
	virtual const char* Student_footer() { NaN; }

	virtual const char* EnterErr() { NaN; }
	virtual const char* EmptyErr() { NaN; }
	virtual const char* Len() { NaN; }
	virtual const char* NumRangeErr() { NaN; }
	virtual const char* GBErr() { NaN; }

	virtual const char* GenderMan() { NaN; }
	virtual const char* GenderFem() { NaN; }
};

class rus : public phrases {
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
	const char* GoMM() { return "��������� � ����� � ������� ����"; }
	const char* Ftry() { return "������� ������� ����..."; }
	const char* Fope() { return "���� ������"; }
	const char* Ferr() { return "������! ���������� �����"; }
	const char* Femp() { return "���� ����. �������� ������"; }
	const char* FnDB() { return "���� - �� ���� ������. �������� ������"; }
	const char* FceateErr() { return "���� � ����� ������ ����������. �������� �����"; }
	const char* DBmenu_header(string  DBname) {
		str = "���� ������: " + DBname;
		return str.c_str();
	}
	const char* ShowDB() { return "�������� ���� ������"; }
	const char* AddEntry() { return "�������� ����� ������"; }
	const char* Task44() { return "������� �������� - 44"; }
	const char* DBmenu_footer() {
		return "��� �������������� ��� �������� �����������:\n'�������� ���� ������'.\n��� ���������� ������� �������� � ������";
	}

	const char* Student_header(string DBname, string Name, string Surname, string MidName, string GradeBook) {
		str = "���� ������: " + DBname + "\n\t�������: " + Surname + ' ' + Name + ' ' + MidName + ", " + GradeBook;
		return str.c_str();
	}
	const char* Name() { return "���"; }
	const char* Surname() { return "�������"; }
	const char* MidName() { return "��������"; }
	const char* Gender() { return "���"; }
	const char* Gender(int16_t Gender) {
		if (Gender == 0) return "���: �������";
		if (Gender == 1) return "���: �������";
		return "���: -";
	}
	const char* Birth() { return "���� ��������"; }
	const char* UniYear() { return "��� �����������"; }
	const char* Faculty() { return "���������"; }
	const char* Departament() { return "�������"; }
	const char* Group() { return "������"; }
	const char* GrBookNum() { return "����� �������� ������"; }
	const char* GoEnterGr() { return "������� � ����� ������"; }
	const char* DEL_stud() { return "������� ��������"; }
	const char* GoDBmenu() { return "��������� � ���� ���� ������"; }
	const char* Student_footer() { return "���� �� ��������� ��� ���� ������������ ������,\n�� ��� ������ � ���� ���� ������ ������ ������������� ���������.."; }

	const char* EnterErr() { return "������������ ������������ �������"; }
	const char* EmptyErr() { return "�� ������ �� �����. ���������� �����"; }
	const char* Len() { return "���������� ����� �����: "; }
	const char* NumRangeErr() { return "������������ �����"; }
	const char* GBErr() { return "������� � ����� ������� �������� ������ ��� ����������"; }

	const char* GenderMan() { return "�������"; }
	const char* GenderFem() { return "�������"; }
};

class eng : public phrases {
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
	const char* GoMM() { return "Save and go to main menu"; }
	const char* Ftry() { return "Trying to open file..."; }
	const char* Fope() { return "File open"; }
	const char* Ferr() { return "Error! Try again"; }
	const char* Femp() { return "The file is empty. Choose another"; }
	const char* FnDB() { return "The file - not a database. Choose another"; }
	const char* FceateErr() { return "A file with the same name exists. Try again"; }
	const char* DBmenu_header(string DBname) {
		str = "Database: " + DBname;
		return str.c_str();
	}
	const char* ShowDB() { return "Show database"; }
	const char* AddEntry() { return "Add New Entry"; }
	const char* Task44() { return "Task of variant - 44"; }
	const char* DBmenu_footer() {
		return "To edit or delete use:\n'Show database'.\nYou must select a student in the list.";
	}

	const char* Student_header(string DBname, string Name, string Surname, string MidName, string GradeBook) {
		str = "���� ������: " + DBname + "\n\t�������: " + Surname + ' ' + Name + ' ' + MidName + ", " + GradeBook;
		return str.c_str();
	}
	const char* Name() { return "Name"; }
	const char* Surname() { return "Surname"; }
	const char* MidName() { return "Middle name"; }
	const char* Gender() { return "Gender"; }
	const char* Gender(int16_t Gender) {
		if (Gender == 0) return "Gender: female";
		if (Gender == 1) return "Gender: male";
		return "Gender: -";
	}
	const char* Birth() { return "Date of birth"; }
	const char* UniYear() { return "Year of admission"; }
	const char* Faculty() { return "Faculty"; }
	const char* Departament() { return "Departament"; }
	const char* Group() { return "Group"; }
	const char* GrBookNum() { return "Gradebook number"; }
	const char* GoEnterGr() { return "Go to enter grades"; }
	const char* DEL_stud() { return "Delete student"; }
	const char* GoDBmenu() { return "Go to database menu"; }
	const char* Student_footer() { return "If you don't fill in all the fields of personal data,\nwhen you exit the data base menu sudent will automatically be deleted.."; }

	const char* EnterErr() { return "Invalid characters present"; }
	const char* EmptyErr() { return "You have not entered anything. Try again"; }
	const char* Len() { return "Allowed word length: "; }
	const char* NumRangeErr() { return "Invalid number"; }
	const char* GBErr() { return "A student with this gradebook number already exists"; }

	const char* GenderMan() { return "Male"; }
	const char* GenderFem() { return "Female"; }
};