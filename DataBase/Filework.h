#pragma once

#include <iostream>
#include "MenuPhrases.h"

class Filework
{
private:
	phrases* Speaker;
	string DB_name;
public:
	Filework(phrases* p) {
		Speaker = p;
	}
	int DB_open();
	int DB_create();
};

