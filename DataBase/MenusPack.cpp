#include "MenusPack.h"


#define CurrentStudent StudentsCreator.GetItem()->stud

void  MenusPack::DrawHelloScreen() {
	cout << "\n\n     _____             __              __              " << endl;
	cout << "    / ___/ __  __ ____/ /___   ____   / /_ _____       " << endl;
	cout << "    \\__ \\ / / / // __  // _ \\ / __ \\ / __// ___/       " << endl;
	cout << "   ___/ // /_/ // /_/ //  __// / / // /_ (__  )        " << endl;
	cout << "  /____/ \\__,_/ \\__,_/ \\___//_/ /_/ \\__//____/         " << endl;
	cout << "      ____          __          __                     " << endl;
	cout << "     / __ \\ ____ _ / /_ ____ _ / /_   ____ _ _____ ___ " << endl;
	cout << "    / / / // __ `// __// __ `// __ \\ / __ `// ___// _ \\" << endl;
	cout << "   / /_/ // /_/ // /_ / /_/ // /_/ // /_/ /(__  )/  __/" << endl;
	cout << "  /_____/ \\__,_/ \\__/ \\__,_//_.___/ \\__,_//____/ \\___/ " << endl;
	cout << "\n                                  by Agabalaev Ivan\n\n";
	system("pause");
}

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
				Student student;
				while (Libr.ReadStudent(&student)){
					StudentsCreator.item_add(student);
				}
				StudentsCreator.Set_to_start();
				Libr.CloseDB();
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
			6, Sp->ShowDB(), Sp->AddEntry(), Sp->EditEntry(), Sp->Task44(), Sp->SaveDB(), Sp->GoMM()))
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
			Libr.ReOpenDB();
			if (StudentsCreator.getListStatus()) {
				StudentsCreator.Set_to_start();
				do {
					Libr.WriteStudent(*CurrentStudent);
					StudentsCreator.moveCursor(1);
				} while (StudentsCreator.GetItem() != StudentsCreator.GetHead()->next_item);
				Libr.CloseDB();
			}
			break;
		case 5:
			if (QuitWarningMenu(Sp->Warning_header2())) {
				StudentsCreator.list_delete();
				return 0;
			}
			break;
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
		case 0:CurrentStudent->SetSurname(Sp); break;
		case 1:CurrentStudent->SetName(Sp); break;
		case 2:CurrentStudent->SetMiddleName(Sp); break;
		case 3:StudentsCreator.GetItem()->stud->SetGender(GenderMenu()); break;
		case 4:CurrentStudent->SetBirth(Sp); break;
		case 5:CurrentStudent->SetUniversityYear(Sp); break;
		case 6:CurrentStudent->SetFaculty(Sp); break;
		case 7:CurrentStudent->SetDepartment(Sp); break;
		case 8:CurrentStudent->SetGroup(Sp); break;
		case 9:
			cout << Sp->GrBookNum() << ": " << CurrentStudent->GetNumGB() << endl;
			cout << Sp->Len() << ": " << 10;
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
		case 10:
			if (CurrentStudent->GetDone() == 9)
				GradesMenu();
			else {
				system("cls");
				cout << Sp->FillErr() << endl << endl;
				system("pause;");
			}
			break;
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
				if (QuitWarningMenu(Sp->Warning_header1())) {
					StudentsCreator.item_delete();
					return 0;
				}
			}
			else return 0;
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
	cout << Sp->Len() << ": " << 10 << endl;
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
		Number++;
	} while (StudentsCreator.GetItem() != StudentsCreator.GetHead()->next_item);
	system("pause");
	return 0;
}

int MenusPack::GradesMenu() {
	while (44) {
		switch (Builder->MenuCreate(Sp->Student_header(Libr.GetDB_short_name(),
			CurrentStudent->GetName(), CurrentStudent->GetSurname(), CurrentStudent->GetNumGB()), "",
			3, Sp->ShowGr(), Sp->EditGrField(), Sp->GoToStodMenu()))
		{
		case 0:
			ShowGr();
			break;
		case 1:
			EditGrades();
			break;
		case 2:
			return 0;
			break;
		default:
			break;
		}
	}
}

int MenusPack::ShowGr() {
	uint8_t is_empty = 1;
	for (int j = 0; j < 10; j++) {
		if (CurrentStudent->GetSession()[0].subjects[j].GetMark() != 0) {
			is_empty = 0;
			break;
		}
	}

	if (is_empty) {
		cout << Sp->SessionEmpty() << endl << endl;
		system("pause");
		return 2;
	}
	cout << Sp->Student_header(Libr.GetDB_short_name(),
		CurrentStudent->GetName(), CurrentStudent->GetSurname(), CurrentStudent->GetNumGB()) << endl;

	for (int i = 0; i < 9; i++) {
		cout << Sp->Session() << ": " << i + 1 << endl;
		for (int j = 0; j < 10; j++) {
			if (CurrentStudent->GetSession()[i].subjects[j].GetMark() != 0) {
				int8_t _mark = CurrentStudent->GetSession()[i].subjects[j].GetMark();
				const char* mark;
				switch (_mark)
				{
				case 1:mark = Sp->Passed(); break;
				case 2:mark = Sp->NotPassed(); break;
				case 3:mark = Sp->Satisf(); break;
				case 4:mark = Sp->Good(); break;
				case 5:mark = Sp->Great(); break;
				default:mark = "NaN"; break;
				}
				cout << setfill(' ') << i + 1 << '.' << j + 1 << '\t' <<
					setw(30) << left << CurrentStudent->GetSession()[i].subjects[j].GetTitle() << mark << endl;
			}
		}
		cout << endl;
	}
	system("pause");
	return 0;
}

int MenusPack::EditGrades() {
	system("cls");
	int16_t* SessionNumber = new int16_t;
	int16_t* SubjectNumber = new int16_t;
	uint8_t is_empty;
	*SessionNumber = 0;
	*SubjectNumber = 0;
	cout << Sp->SessNum_screen() << endl;
	while (44) {
		if (CurrentStudent->GetSession()->subjects->SetIntField(SessionNumber, 1, 9, "", Sp) == 2) return 0;
		*SessionNumber = *SessionNumber - 1;
		is_empty = 1;
		if (*SessionNumber > 0) {
			for (int j = 0; j < 10; j++) {
				if (CurrentStudent->GetSession()[*SessionNumber - 1].subjects[j].GetTitle() != "-") {
					is_empty = 0;
					break;
				}
			}
		}
		if (!is_empty) {
			cout << Sp->PreSessErr() << endl;
			continue;
		}
		else break;
	}
	system("cls");
	cout << Sp->SubjNum_screen(*SessionNumber + 1) << endl;
	if (CurrentStudent->GetSession()->subjects->SetIntField(SubjectNumber, 1, 10, "", Sp) == 2) return 0;
	GradeMenu(*SessionNumber, *SubjectNumber - 1);
	delete SubjectNumber;
	delete SessionNumber;
	return 0;
}

int MenusPack::GradeMenu(int16_t sessNum, int16_t _subjNum) {
	int16_t subjNum = _subjNum;
	while (44) {
		switch (Builder->MenuCreate(Sp->Student_header(Libr.GetDB_short_name(),
			CurrentStudent->GetName(), CurrentStudent->GetSurname(), CurrentStudent->GetNumGB(),
			sessNum, subjNum, CurrentStudent->GetSession()[sessNum].subjects[subjNum].GetTitle(),
			CurrentStudent->GetSession()[sessNum].subjects[subjNum].GetMark()), Sp->Gr_footer(),
			10, Sp->NextSubj(), Sp->PrevSubj(), Sp->Title(), Sp->Passed(), Sp->NotPassed(), Sp->Satisf(), Sp->Good(), Sp->Great(),
			Sp->CleanGrade(), Sp->GoToStodMenu()))
		{
		case 0:
			if (CurrentStudent->GetSession()[sessNum].subjects[subjNum].GetTitle() == "-" ||
				CurrentStudent->GetSession()[sessNum].subjects[subjNum].GetMark() == 0) {
				CurrentStudent->GetSession()[sessNum].subjects[subjNum].SetTitleDefault();
				CurrentStudent->GetSession()[sessNum].subjects[subjNum].SetMarkDefault();
			}
			if (subjNum < 9) subjNum++;
			break;
		case 1:
			if (CurrentStudent->GetSession()[sessNum].subjects[subjNum].GetTitle() == "-" ||
				CurrentStudent->GetSession()[sessNum].subjects[subjNum].GetMark() == 0) {
				CurrentStudent->GetSession()[sessNum].subjects[subjNum].SetTitleDefault();
				CurrentStudent->GetSession()[sessNum].subjects[subjNum].SetMarkDefault();
			}
			if (subjNum > 0) subjNum--;
			break;
		case 2:CurrentStudent->GetSession()[sessNum].subjects[subjNum].SetTitle(Sp); break;
		case 3:CurrentStudent->GetSession()[sessNum].subjects[subjNum].SetMark(1); break;
		case 4:CurrentStudent->GetSession()[sessNum].subjects[subjNum].SetMark(2); break;
		case 5:CurrentStudent->GetSession()[sessNum].subjects[subjNum].SetMark(3); break;
		case 6:CurrentStudent->GetSession()[sessNum].subjects[subjNum].SetMark(4); break;
		case 7:CurrentStudent->GetSession()[sessNum].subjects[subjNum].SetMark(5); break;
		case 8:
			CurrentStudent->GetSession()[sessNum].subjects[subjNum].SetTitleDefault();
			CurrentStudent->GetSession()[sessNum].subjects[subjNum].SetMarkDefault();
			break;
		case 9:
			if (CurrentStudent->GetSession()[sessNum].subjects[subjNum].GetTitle() == "-" ||
				CurrentStudent->GetSession()[sessNum].subjects[subjNum].GetMark() == 0) {
				if (QuitWarningMenu(Sp->Warning_header1())) {
					CurrentStudent->GetSession()[sessNum].subjects[subjNum].SetTitleDefault();
					CurrentStudent->GetSession()[sessNum].subjects[subjNum].SetMarkDefault();
					return 0;
				}			
			}
			else return 0;
			break;
		default:
			break;
		}
	}
}

int MenusPack::QuitWarningMenu(const char* header){
	while (44){
		switch (Builder->MenuCreate(header, "", 2, Sp->Yes(), Sp->No()))
		{
		case 0:return 1;
		case 1:return 0;
		default:break;
		}
	}
}

int MenusPack::Task44(){
	int gender;
	switch (Builder->MenuCreate(Sp->Gender(), "", 2, Sp->GenderFem(), Sp->GenderMan()))
	{
	case 0:gender = 0;
	case 1:gender = 1;
	default:break;
	}
	return 0;
}

