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
		switch (Builder->MenuCreate(Sp->DBmenu_header(Libr.GetDB_short_name()), "",
			5, Sp->ShowDB(), Sp->AddEntry(), Sp->EditEntry(), Sp->Task44(), Sp->GoMM()))
		{
		case 0:
			ShowDB();
			break;
		case 1:
			StudentMenu(StudentsCreator.item_add());
			break;
		case 2:
			EnterGB_Screen();
			break;
		case 3:
			break;
		case 4:
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
	Date DefaultDate;
	string str;
	while (44) {
		switch (Builder->MenuCreate(Sp->Student_header(Libr.GetDB_short_name(),
			CurrentStudent->GetName(), CurrentStudent->GetSurname(), CurrentStudent->GetNumGB()),Sp->Student_footer(CurrentStudent->GetDone()),
			13, Sp->Surname(), Sp->Name(), Sp->MidName(), Sp->Gender(), Sp->Birth(),
			Sp->UniYear(), Sp->Faculty(), Sp->Department(), Sp->Group(), Sp->GrBookNum(),
			Sp->GoEnterGr(),Sp->DEL_stud(), Sp->GoDBmenu()))
		{
		case 0:while (!(CurrentStudent->SetSurname(Sp))) {} break;
		case 1:while (!(CurrentStudent->SetName(Sp))) {} break;
		case 2:while (!(CurrentStudent->SetMiddleName(Sp))) {} break;
		case 3:StudentsCreator.GetItem()->stud->SetGender(GenderMenu()); break;
		case 4:while (!(CurrentStudent->SetBirth(Sp))) {} break;
		case 5:while (!(CurrentStudent->SetUniversityYear(Sp))) {} break;
		case 6:while (!(CurrentStudent->SetFaculty(Sp))) {} break;
		case 7:while (!(CurrentStudent->SetDepartment(Sp))) {} break;
		case 8:while (!(CurrentStudent->SetGroup(Sp))) {} break;
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
				CurrentStudent->GetGender() == -1 ||
				CurrentStudent->GetBirth() == DEFAULT_DATE ||
				CurrentStudent->GetUniversityYear() == 0 ||
				CurrentStudent->GetFaculty() == "-" ||
				CurrentStudent->GetDepartment() == "-" ||
				CurrentStudent->GetGroup() == "-" ||
				CurrentStudent->GetNumGB() == "-") {
				StudentsCreator.item_delete();
			}
			return 0;
			break;
		default:
			break;
		}
	}
}

int MenusPack::EnterGB_Screen() {
	if (!StudentsCreator.getListStatus()) {
		cout << Sp->EmptyDB() << endl << endl;
		system("pause");
		return 2;
	}
	string str;
	list* noname;
	system("cls");
	cout << Sp->EnterGBN() << endl;
	cout << Sp->Len() << 10 << endl;
	while (44) {
		str = StudentsCreator.GetItem()->stud->SetNumGB(Sp);
		if (str == "!Q") return 2;
		noname = StudentsCreator.FindGB(str);
		if (noname == nullptr) {
			cout << Sp->NaNGBN() << endl;
			continue;
		}
		else break;
	}
	StudentMenu(noname->stud);
	return 1;
}

int MenusPack::ShowDB() {
	if (!StudentsCreator.getListStatus()) {
		cout << Sp->EmptyDB() << endl << endl;
		system("pause");
		return 2;
	}
	system("cls");
	string gender;
	char B = (char)-107;
	int Number = 1;
	StudentsCreator.Set_to_start();
	cout << setw(145) << setfill(B) << B << endl;
	//cout << B << setw(20) << left << "#" <<
	//	B << setw(20) << left << Sp->Surname() <<
	//	B << setw(20) << left << Sp->Name() <<
	//	B << setw(20) << left << Sp->MidName() <<
	//	B << setw(10) << left << Sp->GrBookNum() <<
	//	B << setw(15) << left << Sp->Group() <<
	//	B << setw(10) << left << Sp->Gender() <<
	//	B << setw(15) << left << Sp->Birth() <<
	//	B << setw(20) << left << Sp->UniYear() <<
	//	B << setw(10) << left << Sp->Faculty() <<
	//	B << setw(10) << left << Sp->Department() << B << endl;

	do {
		if (CurrentStudent->GetGender() == 0) gender = Sp->GenderFem();
		else gender = Sp->GenderMan();
		cout << setfill(' ') << '|' << setw(4) << left << Number <<
			'|' << setw(20) << left << CurrentStudent->GetSurname() <<
			'|' << setw(20) << left << CurrentStudent->GetName() <<
			'|' << setw(20) << left << CurrentStudent->GetMiddleName() <<
			'|' << setw(10) << left << CurrentStudent->GetNumGB() <<
			'|' << setw(15) << left << CurrentStudent->GetGroup() <<
			'|' << setw(10) << left << gender <<
			'|' << setw(10) << left << CurrentStudent->GetBirth() <<
			'|' << setw(4) << left << CurrentStudent->GetUniversityYear() <<
			'|' << setw(10) << left << CurrentStudent->GetFaculty() <<
			'|' << setw(10) << left << CurrentStudent->GetDepartment() << '|' << endl;
		cout << setw(145) << setfill(B) << B << endl;
		StudentsCreator.moveCursor(1);
	} while (StudentsCreator.GetItem() != StudentsCreator.GetHead()->next_item);
	system("pause");
	return 0;
}