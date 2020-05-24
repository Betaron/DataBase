#include "MenusPack.h"

#define CurrentStudent StudentsCreator.GetItem()->stud

int MenusPack::MainMenu() {
	while (44) {
		switch (Builder->MenuCreate(Sp->MainMenu_header(), Sp->MainMenu_footer(),
			4, Sp->CreateDB(), Sp->LoadDB(), Sp->LengSet(), Sp->Exit()))
		{
		case 0:
			if (Libr.DB_create(Sp)) {
				DatabaseMenu();
			}
			break;
		case 1:
			if (Libr.DB_open(Sp)) {
				DatabaseMenu();
			}
			break;
		case 2:
			LangMenu();
			break;
		case 3:
			return 0;
		default:
			break;
		}
	}
}

int MenusPack::LangMenu() {
	switch (Builder->MenuCreate(Sp->LengSet(), "",
		2, Sp->Lang_rus(), Sp->Lang_eng()))
	{
	case 0: Sp = new rus; break;
	case 1: Sp = new eng; break;
	default: break;
	}
	return 0;
}

int MenusPack::DatabaseMenu() {
	while (44) {
		switch (Builder->MenuCreate(Sp->DBmenu_header(Libr.GetDB_short_name()), Sp->DBmenu_footer(),
			4, Sp->ShowDB(), Sp->AddEntry(), Sp->Task44(), Sp->GoMM()))
		{
		case 0:
			break;
		case 1:
			StudentMenu(StudentsCreator.item_add());
			break;
		case 2:
			break;
		case 3:
			Libr.CloseDB();
			return 0;
		default:
			break;
		}
	}
}

int MenusPack::GenderMenu() {
	while (44) {
		switch (Builder->MenuCreate(Sp->Gender(CurrentStudent->GetGender()), "", 2, Sp->GenderFem(), Sp->GenderMan()))
		{
		case 0:return 0;
		case 1:return 1;
		default:break;
		}
	}
}

int MenusPack::StudentMenu(Student*) {
	int res;
	Date DefaultDate;
	string str;
	while (44) {
		switch (Builder->MenuCreate(Sp->Student_header(Libr.GetDB_short_name(),
			CurrentStudent->GetName(), CurrentStudent->GetSurname(),
			CurrentStudent->GetMiddleName(), CurrentStudent->GetNumGB()),Sp->Student_footer(),
			13, Sp->Surname(), Sp->Name(), Sp->MidName(), Sp->Gender(), Sp->Birth(),
			Sp->UniYear(), Sp->Faculty(), Sp->Departament(), Sp->Group(), Sp->GrBookNum(),
			Sp->GoEnterGr(),Sp->DEL_stud(), Sp->GoDBmenu()))
		{
		case 0:while (!(res = CurrentStudent->SetSurname(Sp))) {} break;
		case 1:while (!(res = CurrentStudent->SetName(Sp))) {} break;
		case 2:while (!(res = CurrentStudent->SetMiddleName(Sp))) {} break;
		case 3:StudentsCreator.GetItem()->stud->SetGender(GenderMenu()); break;
		case 4:while (!(res = CurrentStudent->SetBirth(Sp))) {} break;
		case 5:while (!(res = CurrentStudent->SetUniversityYear(Sp))) {} break;
		case 6:while (!(res = CurrentStudent->SetFaculty(Sp))) {} break;
		case 7:while (!(res = CurrentStudent->SetDepartment(Sp))) {} break;
		case 8:while (!(res = CurrentStudent->SetGroup(Sp))) {} break;
		case 9:
			cout << Sp->GrBookNum() << ": " << CurrentStudent->GetNumGB() << endl;
			cout << Sp->Len() << 10;
			while (44) {
				str = CurrentStudent->SetNumGB(Sp);
				if (str == "!Q") break;
				if (StudentsCreator.FindGB(str) == nullptr) {
					CurrentStudent->SetNumGB(0, str, Sp);
					break;
				}
				else CurrentStudent->SetNumGB(1, str, Sp);
			}
			break;
		case 10:break;
		case 11:
			StudentsCreator.item_delete();
			return 0;
			break;
		case 12:
			if (CurrentStudent->GetName() == "-" ||
				CurrentStudent->GetSurname() == "-" ||
				CurrentStudent->GetMiddleName() == "-" ||
				CurrentStudent->GetGender() == -1 ||
				CurrentStudent->GetBirth() == DefaultDate ||
				CurrentStudent->GetUniversityYear() == 0 ||
				CurrentStudent->GetFaculty() == "-" ||
				CurrentStudent->GetDepartment() == "-" ||
				CurrentStudent->GetGroup() == "-") {
				StudentsCreator.item_delete();
			}
			return 0;
			break;
		default:
			break;
		}
	}
}

