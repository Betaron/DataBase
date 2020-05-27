#include "MenusPack.h"
#include "Wincrypt.h"

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
		{
			if (Libr.DB_open(Sp)) {
				Student student;
				HCRYPTPROV CrProv;
				HCRYPTKEY CrKey;
				HCRYPTHASH Hash;
				DWORD PassLen;
				DWORD DataLen;
				CHAR pass[] = "superpuperpassword";
				PassLen = strlen(pass);
				DataLen = sizeof(Student);
				if (!CryptAcquireContext(&CrProv, NULL, NULL, PROV_RSA_FULL, 0))return -1;
				if (!CryptCreateHash(CrProv, CALG_MD5, 0, 0, &Hash)) return -1;
				if (!CryptHashData(Hash, (BYTE*)pass, PassLen, 0)) return -1;
				if (!CryptDeriveKey(CrProv, CALG_RC4, Hash, CRYPT_EXPORTABLE, &CrKey))return -1;
				while (Libr.ReadStudent(&student)) {
					if (!CryptDecrypt(CrKey, NULL, TRUE, 0, (BYTE*)&student, &DataLen)) return -1;
					StudentsCreator.item_add(student);
				}
				StudentsCreator.Set_to_end();
				if (Hash)
					if (!(CryptDestroyHash(Hash))) {
						cout << "HASH ERROR!" << endl;
						return -1;
					}
				if (CrKey)
					if (!(CryptDestroyKey(CrKey))) {
						cout << "KEY ERROR!" << endl;
						return -1;
					}
				if (CrProv)
					if (!(CryptReleaseContext(CrProv, 0))) {
						cout << "PROVIDER ERROR!" << endl;
						return -1;
					}
				Libr.CloseDB();
				DatabaseMenu();
			}
			break;
		}
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
			Task44();
			break;
		case 4:
		{
			Student student;
			HCRYPTPROV CrProv;
			HCRYPTKEY CrKey;
			HCRYPTHASH Hash;
			DWORD PassLen;
			DWORD DataLen;
			CHAR pass[] = "superpuperpassword";
			PassLen = strlen(pass);
			DataLen = sizeof(Student);
			if (!CryptAcquireContext(&CrProv, NULL, NULL, PROV_RSA_FULL, 0))return -1;
			if (!CryptCreateHash(CrProv, CALG_MD5, 0, 0, &Hash)) return -1;
			if (!CryptHashData(Hash, (BYTE*)pass, PassLen, 0)) return -1;
			if (!CryptDeriveKey(CrProv, CALG_RC4, Hash, CRYPT_EXPORTABLE, &CrKey))return -1;
			Libr.ReOpenDB();
			if (StudentsCreator.getListStatus()) {
				StudentsCreator.Set_to_start();
				do {
					student = *CurrentStudent;
					if (!CryptEncrypt(CrKey, NULL, TRUE, 0, (BYTE*)&student, &DataLen, DataLen)) return -1;
					Libr.WriteStudent(student);
					StudentsCreator.moveCursor(1);
				} while (StudentsCreator.GetItem() != StudentsCreator.GetHead()->next_item);
				if (Hash)
					if (!(CryptDestroyHash(Hash))) {
						cout << "HASH ERROR!" << endl;
						return -1;
					}
				if (CrKey)
					if (!(CryptDestroyKey(CrKey))) {
						cout << "KEY ERROR!" << endl;
						return -1;
					}
				if (CrProv)
					if (!(CryptReleaseContext(CrProv, 0))) {
						cout << "PROVIDER ERROR!" << endl;
						return -1;
					}
				Libr.CloseDB();
			}
			break;
		}
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
			CurrentStudent->GetName(), CurrentStudent->GetSurname(),
			CurrentStudent->GetNumGB()),Sp->Student_footer(CurrentStudent->GetDone()),
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
	StudentsCreator.Set_to_start();
	cout << setw(145) << setfill(B) << B << endl;
	do {
		DrawStudent(&StudentsCreator, B);
		StudentsCreator.moveCursor(1);
	} while (StudentsCreator.GetItem() != StudentsCreator.GetHead()->next_item);
	system("pause");
	return 0;
}

void MenusPack::DrawStudent(StudentList* LIST, char B) {
	string gender;
	if (LIST->GetItem()->stud->GetGender() == 0) gender = Sp->GenderFem();
	else gender = Sp->GenderMan();
	cout <<'|' << setfill(' ') << setw(20) << left << LIST->GetItem()->stud->GetSurname() <<
		'|' << setw(20) << left << LIST->GetItem()->stud->GetName() <<
		'|' << setw(20) << left << LIST->GetItem()->stud->GetMiddleName() <<
		'|' << setw(10) << left << LIST->GetItem()->stud->GetNumGB() <<
		'|' << setw(15) << left << LIST->GetItem()->stud->GetGroup() <<
		'|' << setw(10) << left << gender <<
		'|' << setw(10) << left << LIST->GetItem()->stud->GetBirth() <<
		'|' << setw(4) << left << LIST->GetItem()->stud->GetUniversityYear() <<
		'|' << setw(10) << left << LIST->GetItem()->stud->GetFaculty() <<
		'|' << setw(10) << left << LIST->GetItem()->stud->GetDepartment() <<
		'|' << setw(4) << left << round(LIST->GetItem()->stud->GetAverage() * 100) / 100 << '|' << endl;
	cout << setw(145) << setfill(B) << B << endl;
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
				if (CurrentStudent->GetSession()[*SessionNumber - 1].subjects[j].GetMark() != 0) {
					is_empty = 0;
					break;
				}
			}
		}
		if(*SessionNumber == 0) is_empty = 0;
		if (is_empty) {
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

int MenusPack::Task44() {
	int gender = -1;
	switch (Builder->MenuCreate(Sp->Gender(), "", 2, Sp->GenderFem(), Sp->GenderMan()))
	{
	case 0:gender = 0;
	case 1:gender = 1;
	default:break;
	}
	system("cls");
	StudentList more_than_half;
	StudentList less_than_half;

	if (StudentsCreator.getListStatus()) {
		StudentsCreator.Set_to_start();
		do {
			if (CurrentStudent->GetGender() == gender) {
				if (CurrentStudent->GetAverage() != 0) {
					if (CurrentStudent->GetGradeGroup())
						more_than_half.item_add(*StudentsCreator.GetItem()->stud);
					else less_than_half.item_add(*StudentsCreator.GetItem()->stud);
				}
			}
			StudentsCreator.moveCursor(1);
		} while (StudentsCreator.GetItem() != StudentsCreator.GetHead()->next_item);
	}

	char B = (char)-107;
	cout << Sp->Group1() << ":" << endl;
	if (more_than_half.getListStatus()) {
		more_than_half.Set_to_start();
		cout << setw(145) << setfill(B) << B << endl;
		do {
			DrawStudent(&more_than_half, B);
			more_than_half.moveCursor(1);
		} while (more_than_half.GetItem() != more_than_half.GetHead()->next_item);
	}

	DrawSucsessful(&more_than_half, B);
	cout << "\n############################\n\n";

	cout << Sp->Group2() << ":" << endl;
	if (less_than_half.getListStatus()) {
		less_than_half.Set_to_start();
		cout << setw(145) << setfill(B) << B << endl;
		do {
			DrawStudent(&less_than_half, B);
			less_than_half.moveCursor(1);
		} while (less_than_half.GetItem() != less_than_half.GetHead()->next_item);
	}
	DrawSucsessful(&less_than_half, B);
	system("pause");
	more_than_half.list_delete();
	less_than_half.list_delete();
	return 0;
}

void MenusPack::DrawSucsessful(StudentList* LIST, char B){
	double Max = 1;
	double Min = 6;
	double LocalAver = 0;

	if (LIST->getListStatus()) {
		LIST->Set_to_start();
		do {
			LocalAver = LIST->GetItem()->stud->GetAverage();
			if (LocalAver > 1) {
				if (LocalAver > Max)Max = LocalAver;
				if (LocalAver < Min)Min = LocalAver;
			}
			LIST->moveCursor(1);
		} while (LIST->GetItem() != LIST->GetHead()->next_item);
	}

	cout << Sp->mostSuccessful() << ":" << endl;
	if (Max != 1) {
		LIST->Set_to_start();
		cout << setw(145) << setfill(B) << B << endl;
		do {
			if (Max == LIST->GetItem()->stud->GetAverage())
				DrawStudent(LIST, B);
			LIST->moveCursor(1);
		} while (LIST->GetItem() != LIST->GetHead()->next_item);
	}

	cout << Sp->leastSuccessful() << ":" << endl;
	if (Min != 6) {
		LIST->Set_to_start();
		cout << setw(145) << setfill(B) << B << endl;
		do {
			if (Min == LIST->GetItem()->stud->GetAverage())
				DrawStudent(LIST, B);
			LIST->moveCursor(1);
		} while (LIST->GetItem() != LIST->GetHead()->next_item);
	}
}