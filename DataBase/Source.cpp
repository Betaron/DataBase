#include <iostream>
#include "Windows.h"
#include "MenuPhrases.h"
#include "menu.h"



using namespace	std;

int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	phrases* Sp;
	Sp = new eng;

	//cout << Sp->MainMenu_header() << endl;
	//Sp = new rus;
	//cout << Sp->MainMenu_header() << endl;

	Menu* Builder = new Menu;
	
	Builder->MenuCreate(3, Sp->CreateDB(), Sp->LoadDB(), Sp->LengSet());

	return 0;
}