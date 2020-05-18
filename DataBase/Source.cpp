#include <iostream>
#include "Windows.h"
#include "MenuPhrases.h"
#include "menu.h"

using namespace	std;

int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	phrases* Sp; // Sp - speaker
	Sp = new eng;

	Menu* Builder = new Menu;
	//Builder->MenuCreate(2, "aaa", "eee","f1111", "f2222" );
	while (44) {
		switch (Builder->MenuCreate(Sp->MainMenu_header(), Sp->MainMenu_footer(), 4, Sp->CreateDB(), Sp->LoadDB(), Sp->LengSet(), Sp->Exit()))
		{
		case 0:
			break;
		case 1:
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