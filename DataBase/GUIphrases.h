#pragma once

#include "Windows.h"
#include <string>
#define NaN return "NaN"

using namespace	std;

class phrases {
protected:
	string str;
	string _str;
public:
	phrases() {
		system("mode con cols=145 lines=25");
		SetConsoleCP(1251);
		SetConsoleOutputCP(1251);
	}
	virtual const char* MainMenu_header() { NaN; }
	virtual const char* MainMenu_footer() { NaN; }
	virtual const char* CreateDB() { NaN; }
	virtual const char* LoadDB() { NaN; }
	virtual const char* LengSet() { NaN; }
	virtual const char* Exit() { NaN; }
	virtual const char* LangSet_header() { NaN; }
	virtual const char* Lang_eng() { NaN; }
	virtual const char* Lang_rus() { NaN; }
	virtual const char* DBname_ivite() { NaN; }
	virtual const char* GoMM() { NaN; }
	virtual const char* Ftry() { NaN; }
	virtual const char* Fope() { NaN; }
	virtual const char* Ferr() { NaN; }
	virtual const char* Femp() { NaN; }
	virtual const char* FnDB() { NaN; }
	virtual const char* FceateErr() { NaN; }
	virtual const char* DBmenu_header(string) { NaN; }
	virtual const char* ShowDB() { NaN; }
	virtual const char* AddEntry() { NaN; }
	virtual const char* EditEntry() { NaN; }
	virtual const char* Task44() { NaN; }

	virtual const char* Student_header(string, string, string, string) { NaN; }
	virtual const char* Name() { NaN; }
	virtual const char* Surname() { NaN; }
	virtual const char* MidName() { NaN; }
	virtual const char* Gender() { NaN; }
	virtual const char* Gender(int16_t) { NaN; }
	virtual const char* Birth() { NaN; }
	virtual const char* UniYear() { NaN; }
	virtual const char* Faculty() { NaN; }
	virtual const char* Department() { NaN; }
	virtual const char* Group() { NaN; }
	virtual const char* GrBookNum() { NaN; }
	virtual const char* GoEnterGr() { NaN; }
	virtual const char* DEL_stud() { NaN; }
	virtual const char* GoDBmenu() { NaN; }
	virtual const char* Student_footer(int) { NaN; }

	virtual const char* EnterErr() { NaN; }
	virtual const char* EmptyErr() { NaN; }
	virtual const char* Len() { NaN; }
	virtual const char* NumRangeErr() { NaN; }
	virtual const char* GBErr() { NaN; }

	virtual const char* GenderMan() { NaN; }
	virtual const char* GenderFem() { NaN; }

	virtual const char* EnterGBN() { NaN; }
	virtual const char* NaNGBN() { NaN; }
	virtual const char* EmptyDB() { NaN; }
};

class rus : public phrases {
public:
	const char* MainMenu_header() { return "Главное меню"; }
	const char* MainMenu_footer() { return "Для перемещения используйте стрелки.'Enter', чтобы выбрать\nДля отмены состояния ввода введите '!Q'"; }
	const char* CreateDB() { return "Создать базу данных"; }
	const char* LoadDB() { return "Загрузить базу данных"; }
	const char* LengSet() { return "Выбрать язык"; }
	const char* Exit() { return "Выход"; }
	const char* Lang_eng() { return "Английский"; }
	const char* Lang_rus() { return "Русский"; }
	const char* DBname_ivite() { return "Введите название базы данных"; }
	const char* GoMM() { return "Сохранить и выйти в главное меню"; }
	const char* Ftry() { return "Попытка открыть файл..."; }
	const char* Fope() { return "Файл открыт"; }
	const char* Ferr() { return "Ошибка! Попробуйте снова"; }
	const char* Femp() { return "Файл пуст. Выберите другой"; }
	const char* FnDB() { return "Файл - не база данных. Выберите другой"; }
	const char* FceateErr() { return "Файл с таким именем существует. Попройте снова"; }
	const char* DBmenu_header(string  DBname) {
		str = "База данных: " + DBname;
		return str.c_str();
	}
	const char* ShowDB() { return "Показать базу данных"; }
	const char* AddEntry() { return "Добавить новую запись о студенте"; }
	const char* EditEntry() { return "Редатировать запись о студенте"; }
	const char* Task44() { return "Задание варианта - 44"; }

	const char* Student_header(string DBname, string Name, string Surname, string GradeBook) {
		str = "База данных: " + DBname + "\n\tСтудент: " + Surname + ' ' + Name + ", " + GradeBook;
		return str.c_str();
	}
	const char* Name() { return "Имя"; }
	const char* Surname() { return "Фамилия"; }
	const char* MidName() { return "Отчество (если есть)"; }
	const char* Gender() { return "Пол"; }
	const char* Gender(int16_t Gender) {
		if (Gender == 0) return "Пол: женский";
		if (Gender == 1) return "Пол: мужской";
		return "Пол: -";
	}
	const char* Birth() { return "Дата рождения"; }
	const char* UniYear() { return "Год поступления"; }
	const char* Faculty() { return "Факультет"; }
	const char* Department() { return "Кафедра"; }
	const char* Group() { return "Группа"; }
	const char* GrBookNum() { return "Номер зачётной книжки"; }
	const char* GoEnterGr() { return "Перейти к вводу оценок"; }
	const char* DEL_stud() { return "Удалить студента"; }
	const char* GoDBmenu() { return "Вернуться к меню базы данных"; }
	const char* Student_footer(int Done) { 
		this->_str = to_string(Done) + "/9 полей заполнено\n" +
		"Если не заполнить все поля персональных данных,\nто при выходе в меню базы данных судент автоматичекси удалится.." +
		"\n\nПрежде чем заполнять год поступления, необходимо указать дату рождения**";
		return this->_str.c_str();
	}

	const char* EnterErr() { return "Присутствуют недопустимые символы"; }
	const char* EmptyErr() { return "Вы ничего не ввели. Попробуйте снова"; }
	const char* Len() { return "Допустимая длина слова: "; }
	const char* NumRangeErr() { return "Некорректное число"; }
	const char* GBErr() { return "Студент с таким номером зачётной книжки уже существует"; }

	const char* GenderMan() { return "Мужской"; }
	const char* GenderFem() { return "Женский"; }

	const char* EnterGBN() { return "Введите номер зачётной книжки"; }
	const char* NaNGBN() { return "Студент с данным номером зачётной книжки не найден"; }
	const char* EmptyDB() { return "База данных пуста"; }
};

class eng : public phrases {
public:
	const char* MainMenu_header() { return "Main menu"; }
	const char* MainMenu_footer() { return "Use arrows to move. 'Enter' to choose\nTo cancel input state enter '!Q'"; }
	const char* CreateDB() { return "Create a database"; }
	const char* LoadDB() { return "Load a database"; }
	const char* LengSet() { return "Select language"; }
	const char* Exit() { return "Exit"; }
	const char* Lang_eng() { return  "English"; }
	const char* Lang_rus() { return  "Russian"; }
	const char* DBname_ivite() { return "Enter database name"; }
	const char* GoMM() { return "Save and go to main menu"; }
	const char* Ftry() { return "Trying to open file..."; }
	const char* Fope() { return "File open"; }
	const char* Ferr() { return "Error! Try again"; }
	const char* Femp() { return "The file is empty. Choose another"; }
	const char* FnDB() { return "The file - not a database. Choose another"; }
	const char* FceateErr() { return "A file with the same name exists. Try again"; }
	const char* DBmenu_header(string DBname) {
		str = "Database: " + DBname;
		return str.c_str();
	}
	const char* ShowDB() { return "Show database"; }
	const char* AddEntry() { return "Add new entry about student"; }
	const char* EditEntry() { return "Edit entry about student"; }
	const char* Task44() { return "Task of variant - 44"; }

	const char* Student_header(string DBname, string Name, string Surname, string GradeBook) {
		str = "База данных: " + DBname + "\n\tСтудент: " + Surname + ' ' + Name + ", " + GradeBook;
		return str.c_str();
	}
	const char* Name() { return "Name"; }
	const char* Surname() { return "Surname"; }
	const char* MidName() { return "Middle name (if there is)"; }
	const char* Gender() { return "Gender"; }
	const char* Gender(int16_t Gender) {
		if (Gender == 0) return "Gender: female";
		if (Gender == 1) return "Gender: male";
		return "Gender: -";
	}
	const char* Birth() { return "Date of birth"; }
	const char* UniYear() { return "Year of admission"; }
	const char* Faculty() { return "Faculty"; }
	const char* Department() { return "Departament"; }
	const char* Group() { return "Group"; }
	const char* GrBookNum() { return "Gradebook number"; }
	const char* GoEnterGr() { return "Go to enter grades"; }
	const char* DEL_stud() { return "Delete student"; }
	const char* GoDBmenu() { return "Go to database menu"; }
	const char* Student_footer(int Done) { 
		this->_str = to_string(Done) + "/9 fields filled\n" +
		"If you don't fill in all the fields of personal data,\nwhen you exit the data base menu sudent will automatically be deleted.." +
		"\n\nBefore filling in the year of receipt, you must specify the date of birth **"; 
		return this->_str.c_str();
	}

	const char* EnterErr() { return "Invalid characters present"; }
	const char* EmptyErr() { return "You have not entered anything. Try again"; }
	const char* Len() { return "Allowed word length: "; }
	const char* NumRangeErr() { return "Invalid number"; }
	const char* GBErr() { return "A student with this gradebook number already exists"; }

	const char* GenderMan() { return "Male"; }
	const char* GenderFem() { return "Female"; }

	const char* EnterGBN() { return "Enter gradebook number"; }
	const char* NaNGBN() { return "Student with this gradebook number not found"; }
	const char* EmptyDB() { return "Database is empty"; }
};