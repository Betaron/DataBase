#pragma once

#include <iostream>
#include "MenuPhrases.h"
#include <string>
#include <fstream>

class Filework
{
private:
	string DB_name;
	fstream DB;
public:
	int DB_open(phrases*);
	int DB_create(phrases*);
};

