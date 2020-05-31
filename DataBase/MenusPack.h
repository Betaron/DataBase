#pragma once
#include <iostream>
#include "GUIPhrases.h"
#include "menu.h"
#include "StudentList.h"
#include "Filework.h"

class MenusPack
{
private:
	phrases* Sp = new eng;
	Menu* Builder = new Menu;
	Filework Libr;
	StudentList StudentsCreator; 
public:
	~MenusPack() {
		delete Sp;
		delete Builder;
	}
	void DrawHelloScreen();
	int MainMenu();
	int LangMenu();
	int DatabaseMenu();
	int StudentMenu();
	int GenderMenu();
	int EnterGB_Screen();
	int ShowDB();
	int GradesMenu();
	int ShowGr();
	void DrawStudent(StudentList*, char);
	int EditGrades();
	int GradeMenu(int16_t, int16_t);
	int QuitWarningMenu(const char*);
	int Task44();
	void DrawSucsessful(StudentList*, char);
};