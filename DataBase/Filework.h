#pragma once

#include <iostream>
#include <fstream>
#include <string>

#include "Student.h"
#include "GUIPhrases.h"
#include "Menu.h"

class Filework
{
private:
	string DB_name;
	string DB_short_name;
	fstream DB;
public:
	friend const char* phrases::DBmenu_header(string);
	int DB_open(phrases*);
	int DB_create(phrases*);

	string GetDB_short_name() { return DB_short_name; }
	void CloseDB() { DB.close(); }
	void ReOpenDB();
	void WriteStudent(Student);
	int ReadStudent(Student*);
};