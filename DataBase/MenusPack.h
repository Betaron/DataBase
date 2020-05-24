#pragma once
#include <iostream>
#include "GUIPhrases.h"
#include "menu.h"
#include "StudentList.h"
#include "Filework.h"
#include "Student.h"

class MenusPack
{
private:
	phrases* Sp = new eng; // Sp - speaker
	Menu* Builder = new Menu;
	Filework Libr;
	StudentList StudentsCreator; 
public:
	~MenusPack() {
		delete Sp;
		delete Builder;
	}
	//string strNum(const char*);
	int MainMenu();
	int LangMenu();
	int DatabaseMenu();
	int StudentMenu(Student*);
	int GenderMenu();
};