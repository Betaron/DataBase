#include "Student.h"

#define BufClean cin.clear(); cin.ignore(cin.rdbuf()->in_avail()); _flushall()
#define Symbol BufStr[i]
#define Digits "1234567890"

int setter::SetWordField(char* field, size_t fieldLen, const char* header , phrases* Sp) {
	string BufStr;
	size_t len;
	uint8_t flag = 1;
	if (header != "") {
		cout << header << ": " << field << endl;
		cout << Sp->Len() << ": " << fieldLen;
	}
	while (flag) {
		cout << "\n   " << setfill('.') << setw(fieldLen) << '.' << endl;
		cout << " > ";
		BufClean;
		getline(cin, BufStr);
		if (BufStr == "!Q") return 2;
		if (BufStr.empty()) {
			cout << Sp->EmptyErr();
			continue;
		}
		len = BufStr.length();
		if (len > fieldLen) {
			cout << Sp->Len() << ": " << fieldLen;
			continue;
		}
		for (size_t i = 0; i < len; i++) {
			if (!(((int)Symbol >= 65 && (int)Symbol <= 90) ||
				((int)Symbol >= 97 && (int)Symbol <= 122) ||
				((int)Symbol >= -64 && (int)Symbol <= 0) ||
				((int)Symbol >= 48 && (int)Symbol <= 57) ||
				Symbol == '¨' || Symbol == '¸' || Symbol == '-' || Symbol == '.')) {
				cout << Sp->EnterErr();
				break;
			}
			if (i == len - 1) flag = 0;
		}
	}
	strcpy_s(field, fieldLen+1, BufStr.c_str());
	return 1;
}

int setter::SetIntField(int16_t* field, int16_t fieldmin, int16_t fieldmax, const char* header, phrases* Sp) {
	string BufStr;
	size_t i;
	size_t len;
	uint8_t flag = 1;
	if (header != "")
		cout << header << ": " << *field << endl;
	while (flag) {
		BufClean;
		cout << " > ";
		getline(cin, BufStr);
		if (BufStr == "!Q") return 2;
		if (BufStr.empty()) {
			cout << Sp->EmptyErr() << endl;
			continue;
		}
		len = BufStr.length();
		if (len > 9) {
			cout << Sp->EnterErr() << endl;
			continue;
		}
		(BufStr[1] == '+' || BufStr[1] == '-') ? i = 1 : i = 0;
		for (; i < len; i++) {
			if (!(((int)Symbol >= 48 && (int)Symbol <= 57))) {
				cout << Sp->EnterErr() << endl;
				break;
			}
			if (i == len - 1) flag = 0;
		}
		if (flag == 1) continue;
		if (stoi(BufStr) < fieldmin || stoi(BufStr) > fieldmax) {
			flag = 1;
			cout << Sp->NumRangeErr() << endl;
		}
	}
	*field = stoi(BufStr);
	return 1;
}

int setter::SetDateField(Date* field, int16_t fieldmin, int16_t fieldmax, const char* header) {
	string D, M, Y;
	cout << header << ": " << *field << endl;
	while(44){
		BufClean;
		cout << " > ";
		cin >> D;
		if (D == "!Q") return 2;
		if (cin.bad()) continue;
		cin >> M;
		if (M == "!Q") return 2;
		if (cin.bad()) continue;
		cin >> Y;
		if (Y == "!Q") return 2;
		if (cin.bad()) continue;
		if (D.length() > 4 || M.length() > 4 || Y.length() > 4)continue;
		if (!D.find_first_not_of(Digits)) continue;
		if (!M.find_first_not_of(Digits)) continue;
		if (!Y.find_first_not_of(Digits)) continue;
		if (stoi(Y) < fieldmin || stoi(Y) > fieldmax) continue;
		if (stoi(D) < -INT32_MAX || stoi(D) > INT32_MAX) continue;
		if (stoi(M) < -INT32_MAX || stoi(M) > INT32_MAX) continue;
		if (field->SetDate(stoi(D), stoi(M), stoi(Y))) break;
	}
	return 1;
}

void Student::SetGender(uint8_t source) { Gender = source; }
int Student::SetBirth(phrases* Sp) { return SetDateField(&Birth, 1950, 2019, Sp->Birth()); }
int Student::SetUniversityYear(phrases* Sp) { 
	if (Birth.GetYear() == 0) {
		Sp->BegSetBurth();
		system("cls");
		return 2;
	}
	return SetIntField(UniversityYear, Birth.GetYear() + 14, 2019, Sp->UniYear(), Sp);
}
int Student::SetName(phrases* Sp) { return SetWordField(Name, 20, Sp->Name(), Sp); }
int Student::SetSurname(phrases* Sp) { return SetWordField(Surname, 20, Sp->Surname(), Sp); }
int Student::SetMiddleName(phrases* Sp) { return SetWordField(MiddleName, 20, Sp->MidName(), Sp); }
int Student::SetFaculty(phrases* Sp) { return SetWordField(Faculty, 10, Sp->Faculty(), Sp); }
int Student::SetDepartment(phrases* Sp) { return SetWordField(Department, 10, Sp->Department(), Sp); }
int Student::SetGroup(phrases* Sp) { return SetWordField(Group, 15, Sp->Group(), Sp); }

string Student::SetNumGB(phrases* Sp) {
	char source[11] = "";
	string res;
	if (SetWordField(source, 10, "", Sp) == 2) res = "!Q";
	 else res = source;
	return res;
}

void Student::SetNumGB(int flag, string str, phrases* Sp) {
	if (flag == 0) strcpy_s(NumGB, 10, str.c_str());
	if (flag == 1) cout << Sp->GBErr();
}

const char* Student::GetName(){ return Name; }
const char* Student::GetSurname(){ return Surname; }
const char* Student::GetMiddleName(){ return MiddleName; }
int16_t Student::GetGender(){ return Gender; }
Date Student::GetBirth(){ return Birth; }
int16_t Student::GetUniversityYear(){ return *UniversityYear; }
const char* Student::GetFaculty(){ return Faculty; }
const char* Student::GetDepartment() { return Department; }
const char* Student::GetGroup(){ return Group; }
const char* Student::GetNumGB(){ return NumGB; }
Education* Student::GetSession() { return session; }

int Student::GetDone() {
	int Done(0);
	if (strcmp(Name, "-")) Done++;
	if (strcmp(Surname, "-")) Done++;
	if (Gender != -1) Done++;
	if (Birth != DEFAULT_DATE) Done++;
	if (*UniversityYear != 0) Done++;
	if (strcmp(Faculty, "-")) Done++;
	if (strcmp(Department, "-")) Done++;
	if (strcmp(Group, "-")) Done++;
	if (strcmp(NumGB, "-")) Done++;
	return Done;
}

int Subject::SetTitle(phrases* Sp) {
	return SetWordField(Title, 30, Sp->Title() , Sp);
}

void Subject::SetTitleDefault() {
	for (uint8_t i = 0; i < 31; i++) Title[i] = 0;
	Title[0] = '-';
}

void Subject::SetMarkDefault() {
	Mark = 0;
}