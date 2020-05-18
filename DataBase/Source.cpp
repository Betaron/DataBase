#include <iostream>
#include "Windows.h"
#include "MenuPhrases.h"
#include "menu.h"
#include "Filework.h"

using namespace	std;

int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	phrases* Sp = new eng; // Sp - speaker
	Menu* Builder = new Menu;
	Filework Libr;

	while (44) {
		switch (Builder->MenuCreate(Sp->MainMenu_header(), Sp->MainMenu_footer(),
					4, Sp->CreateDB(), Sp->LoadDB(), Sp->LengSet(), Sp->Exit()))
		{
		case 0:
			Libr.DB_create(Sp);
			break;
		case 1:
			Libr.DB_open(Sp);
			break;
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
			delete Sp;
			return 0;
		default:
			break;
		}
	}
	return 0;
}