#include <iostream>
#include "Windows.h"
#include "MenuPhrases.h"
#include "menu.h"



using namespace	std;

int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	phrases* Sp;
	Sp = new rus;

	Menu* Builder = new Menu;
	while (44) {
		switch (Builder->MenuCreate(Sp->MainMenu_header(), Sp->MainMenu_footer(),
			4, Sp->CreateDB(), Sp->LoadDB(), Sp->LengSet(), Sp->Exit()))
		{
		case 2:
			switch (Builder->MenuCreate(Sp->LengSet(), "",
				2, Sp->Lang_rus(), Sp->Lang_eng()))
			{
			case 0: Sp = new rus; break;
			case 1: Sp = new eng; break;
			default: break;
			}
			break;
		case 3:
			return 0;
		default:
			break;
		}
	}

	return 0;
}