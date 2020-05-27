#pragma once
#include <iostream>
#include <string>
#include "Windows.h"
#include "Date.h"
#include "GUIPhrases.h"

class setter
{
public:
	int SetWordField(char*, size_t, const char*, phrases*);
	int SetIntField(int16_t*,int16_t, int16_t, const char*, phrases*);
	int SetDateField(Date*, int16_t, int16_t, const char*);
};

class Subject : public setter
{
private:
	char Title[31] = "";
	int8_t Mark;
public:
	Subject() {
		*Title = '-';
		Mark = 0;
	}
	const char* GetTitle() { return Title; }
	int8_t GetMark() { return Mark; }
	int SetTitle(phrases*);
	void SetMark(int8_t source) { Mark = source; }
	void SetTitleDefault();
	void SetMarkDefault();
};

class Education
{
public:
	Subject subjects[10];
};

class Student : setter
{
private:
	char Name[21] = "";
	char Surname[21] = "";
	char MiddleName[21] = "";
	int16_t Gender;
	Date Birth;
	int16_t UniversityYear;
	char Faculty[11] = "";
	char Department[11] = "";
	char Group[16] = "";
	char NumGB[11] = ""; //number of grade book
	Education session[9];
public:
	Student() {
		*Name = '-';
		*Surname = '-';
		*MiddleName = '-';
		Gender = -1;
		UniversityYear = 0;
		*Faculty = '-';
		*Department = '-';
		*Group = '-';
		*NumGB = '-';
	}
	int SetName(phrases*);
	int SetSurname(phrases*);
	int SetMiddleName(phrases*);
	void SetGender(uint8_t);
	int SetBirth(phrases*);
	int SetUniversityYear(phrases*);
	int SetFaculty(phrases*);
	int SetDepartment(phrases*);
	int SetGroup(phrases*);
	string SetNumGB(phrases*);
	void SetNumGB(int, string, phrases*);

	const char* GetName();
	const char* GetSurname();
	const char* GetMiddleName();
	int16_t GetGender();
	Date GetBirth();
	int16_t GetUniversityYear();
	const char* GetFaculty();
	const char* GetDepartment();
	const char* GetGroup();
	const char* GetNumGB();
	int GetDone();
	Education* GetSession();
	double GetAverage();
	int SumGood();
	int SumWorst();
};

