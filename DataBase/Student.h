#pragma once
#include <iostream>
#include <string>
#include "Windows.h"
#include "Date.h"
#include "GUIPhrases.h"

class setter {
public:
	int SetWordField(char*, size_t, const char*, phrases*);
	int SetIntField(int16_t*,int16_t, int16_t, const char*, phrases*);
	int SetDateField(Date*, int16_t, int16_t, const char*);
};

class Student : setter
{
private:
	char Name[20] = "";
	char Surname[20] = "";
	char MiddleName[20] = "";
	int16_t Gender;
	Date Birth;
	int16_t* UniversityYear;
	char Faculty[10] = "";
	char Department[10] = "";
	char Group[15] = "";
	char NumGB[10] = ""; //number of grade book
public:
	Student() {
		*Name = '-';
		*Surname = '-';
		*MiddleName = '-';
		Gender = -1;
		UniversityYear = new int16_t;
		*UniversityYear = 0;
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
	//int SetNumGB();

	const char* GetName();
	const char* GetSurname();
	const char* GetMiddleName();
	int16_t GetGender();
	Date GetBirth();
	int16_t GetUniversityYear();
	const char* GetFaculty();
	const char* GetDepartment();
	const char* GetGroup();
	char* GetNumGB();
};