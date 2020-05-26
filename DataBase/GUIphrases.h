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
	virtual const char* DBmenu_header(string  DBname) { NaN; }
	virtual const char* ShowDB() { NaN; }
	virtual const char* AddEntry() { NaN; }
	virtual const char* EditEntry() { NaN; }
	virtual const char* Task44() { NaN; }
	virtual const char* SaveDB() { NaN; }
	virtual const char* DBmenu_footer() { NaN; }

	virtual const char* Passed() { NaN; }
	virtual const char* NotPassed() { NaN; }
	virtual const char* Satisf() { NaN; }
	virtual const char* Good() { NaN; }
	virtual const char* Great() { NaN; }
	virtual const char* Student_header(string DBname, string Name, string Surname, string GradeBook) { NaN; }
	virtual const char* Student_header(string DBname, string Name, string Surname, string GradeBook, int16_t Session, int16_t subj, string title, int8_t _mark) { NaN; }
	virtual const char* Name() { NaN; }
	virtual const char* Surname() { NaN; }
	virtual const char* MidName() { NaN; }
	virtual const char* Gender() { NaN; }
	virtual const char* Gender(int16_t Gender) { NaN; }
	virtual const char* Birth() { NaN; }
	virtual const char* UniYear() { NaN; }
	virtual const char* Faculty() { NaN; }
	virtual const char* Department() { NaN; }
	virtual const char* Group() { NaN; }
	virtual const char* GrBookNum() { NaN; }
	virtual const char* GoEnterGr() { NaN; }
	virtual const char* DEL_stud() { NaN; }
	virtual const char* GoDBmenu() { NaN; }
	virtual const char* Student_footer(int Done) { NaN; }

	virtual const char* EnterErr() { NaN; }
	virtual const char* EmptyErr() { NaN; }
	virtual const char* Len() { NaN; }
	virtual const char* NumRangeErr() { NaN; }
	virtual const char* GBErr() { NaN; }
	virtual const char* BegSetBirth() { NaN; }

	virtual const char* GenderMan() { NaN; }
	virtual const char* GenderFem() { NaN; }

	virtual const char* EnterGBN() { NaN; }
	virtual const char* NaNGBN() { NaN; }
	virtual const char* EmptyDB() { NaN; }

	virtual const char* FillErr() { NaN; }
	virtual const char* ShowGr() { NaN; }
	virtual const char* SessNum_screen() { NaN; }
	virtual const char* SubjNum_screen(int session) { NaN; }
	virtual const char* EnterSession() { NaN; }
	virtual const char* Session() { NaN; }
	virtual const char* SessionEmpty() { NaN; }
	virtual const char* EditGrField() { NaN; }
	virtual const char* GoToStodMenu() { NaN; }
	virtual const char* PreSessErr() { NaN; }
	virtual const char* Title() { NaN; }
	virtual const char* NextSubj() { NaN; }
	virtual const char* PrevSubj() { NaN; }
	virtual const char* CleanGrade() { NaN; }
	virtual const char* Gr_footer() { NaN; }

	virtual const char* Warning_header1() { NaN; }
	virtual const char* Warning_header2() { NaN; }
	virtual const char* Yes() { NaN; }
	virtual const char* No() { NaN; }
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
	const char* GoMM() { return "Выйти в главное меню"; }
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
	const char* SaveDB() { return "Сохранить базу данных"; }
	const char* DBmenu_footer() { return "Сохранение может занять какое-то время*"; }

	const char* Passed() { return "Зачёт"; }
	const char* NotPassed() { return "Незачёт"; }
	const char* Satisf() { return "3 (Удовл.)"; }
	const char* Good() { return "4 (Хор.)"; }
	const char* Great() { return "5 (Отл.)"; }
	const char* Student_header(string DBname, string Name, string Surname, string GradeBook) {
		str = "База данных: " + DBname + "\n\tСтудент: " + Surname + ' ' + Name + ", " + GradeBook;
		return str.c_str();
	}
	const char* Student_header(string DBname, string Name, string Surname, string GradeBook, int16_t Session, int16_t subj, string title, int8_t _mark) {
		const char* mark;
		switch (_mark)
		{
		case 1:mark = Passed(); break;
		case 2:mark = NotPassed(); break;
		case 3:mark = Satisf(); break;
		case 4:mark = Good(); break;
		case 5:mark = Great(); break;
		default:mark = "NaN"; break;
		}
		str = "База данных: " + DBname + "\n\tСтудент: " + Surname + ' ' + Name + ", " + GradeBook +
			"\n\t\tСессия: " + to_string(Session + 1) +
			"\n\t\tПредмет: " + to_string(subj + 1) + ", " + title + " - " + mark;
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
	const char* GoDBmenu() { return "Вернуться в меню базы данных"; }
	const char* Student_footer(int Done) {
		_str = to_string(Done) + "/9 полей заполнено\n" +
			"Если не заполнить все поля персональных данных,\nто при выходе в меню базы данных судент автоматичекси удалится.." +
			"\n\nПрежде чем заполнять год поступления, необходимо указать дату рождения**";
		return _str.c_str();
	}

	const char* EnterErr() { return "Присутствуют недопустимые символы"; }
	const char* EmptyErr() { return "Вы ничего не ввели. Попробуйте снова"; }
	const char* Len() { return "Допустимая длина слова"; }
	const char* NumRangeErr() { return "Некорректное число"; }
	const char* GBErr() { return "Студент с таким номером зачётной книжки уже существует"; }
	const char* BegSetBirth() { return "Сначала укажите дату рождения"; }

	const char* GenderMan() { return "Мужской"; }
	const char* GenderFem() { return "Женский"; }

	const char* EnterGBN() { return "Введите номер зачётной книжки"; }
	const char* NaNGBN() { return "Студент с данным номером зачётной книжки не найден"; }
	const char* EmptyDB() { return "База данных пуста"; }

	const char* FillErr() { return "Прежде чем перейти к вводу данных о сессии заполние поля персональных данных"; }
	const char* ShowGr() { return "Показать все оценки"; }
	const char* SessNum_screen() { return "Введите номер сессии"; }
	const char* SubjNum_screen(int session) {
		str = "Сессия: " + to_string(session) + "\nВведите номер предмета";
		return str.c_str();
	}
	const char* Session() { return "Сессия"; }
	const char* EnterSession() { return "Ввести сессию"; }
	const char* SessionErr() { return "Данная сессия уже заполнялась.\nДля редактирования воспользуйтесь соответствующим пунктом меню"; }
	const char* SessionEmpty() { return "Не найдено ни одной заполненной сессии"; }
	const char* EditGrField() { return "Редактировать оценки"; }
	const char* GoToStodMenu() { return "Вернуться в меню студента"; }

	const char* PreSessErr() { return "Заполните предыдущие сессии"; }
	const char* Title() { return "Наименование предмета"; }

	const char* NextSubj() { return "Перейти к следующему предмету"; }
	const char* PrevSubj() { return "Перейти к предыдущему предмету"; }
	const char* CleanGrade() { return "Очистить предмет и оценку"; }
	const char* Gr_footer() { return "Если не заполнить оба поля оценки, то они не сохранится"; }

	const char* Warning_header1() { return "Вы уверены, что хотите выйти?\nЗапись не сохранится"; }
	const char* Warning_header2() { return "Вы уверены, что хотите выйти?\nНесохранённые данные будут утеряны*"; }
	const char* Yes() { return "Да, выйти"; }
	const char* No() { return "Нет, остаться"; }
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
	const char* GoMM() { return "Go to main menu"; }
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
	const char* SaveDB() { return "Save database"; }
	const char* DBmenu_footer() { return "Saving may take some time *"; }


	const char* Passed() { return "Passed"; }
	const char* NotPassed() { return "NotPassed"; }
	const char* Satisf() { return "3 (Satisf.)"; }
	const char* Good() { return "4 (Good)"; }
	const char* Great() { return "5 (Great)"; }
	const char* Student_header(string DBname, string Name, string Surname, string GradeBook) {
		str = "Database: " + DBname + "\n\tStudent: " + Surname + ' ' + Name + ", " + GradeBook;
		return str.c_str();
	}
	const char* Student_header(string DBname, string Name, string Surname, string GradeBook, int16_t Session, int16_t subj, string title, int8_t _mark) {
		const char* mark;
		switch (_mark)
		{
		case 1:mark = Passed(); break;
		case 2:mark = NotPassed(); break;
		case 3:mark = Satisf(); break;
		case 4:mark = Good(); break;
		case 5:mark = Great(); break;
		default:mark = "NaN"; break;
		}
		str = "Database: " + DBname + "\n\tStudent: " + Surname + ' ' + Name + ", " + GradeBook +
			"\n\t\tSession: " + to_string(Session + 1) +
			"\n\t\tSubject: " + to_string(subj + 1) + ", " + title + " - " + mark;
		return str.c_str();
	}
	const char* Name() { return "Name"; }
	const char* Surname() { return "Surname"; }
	const char* MidName() { return "Middle name (if there is)"; }
	const char* Gender() { return "Gender"; }
	const char* Gender(int16_t Gender) {
		if (Gender == 0) return "Gender: Female";
		if (Gender == 1) return "Gender: Male";
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
	const char* GoDBmenu() { return "Return to database menu"; }
	const char* Student_footer(int Done) { 
		_str = to_string(Done) + "/9 fields filled\n" +
		"If you don't fill in all the fields of personal data,\nwhen you exit the data base menu sudent will automatically be deleted.." +
		"\n\nBefore filling in the year of receipt, you must specify the date of birth **"; 
		return _str.c_str();
	}

	const char* EnterErr() { return "Invalid characters present"; }
	const char* EmptyErr() { return "You have not entered anything. Try again"; }
	const char* Len() { return "Allowed word length"; }
	const char* NumRangeErr() { return "Invalid number"; }
	const char* GBErr() { return "A student with this gradebook number already exists"; }
	const char* BegSetBirth() { return "First enter date of birth"; }

	const char* GenderMan() { return "Male"; }
	const char* GenderFem() { return "Female"; }

	const char* EnterGBN() { return "Enter gradebook number"; }
	const char* NaNGBN() { return "Student with this gradebook number not found"; }
	const char* EmptyDB() { return "Database is empty"; }

	const char* FillErr() { return "Before moving on to entering session data, fill in the personal data fields"; }
	const char* ShowGr() { return "Show all grades"; }
	const char* SessNum_screen() { return "Enter session number"; }
	const char* SubjNum_screen(int session) {
	str = "Session: " + to_string(session) + "\nEnter subject number";
	return str.c_str();
	}
	const char* Session() { return "Session"; }
	const char* EnterSession() { return "Enter session"; }
	const char* SessionEmpty() { return "No filled sessions found"; }
	const char* EditGrField() { return "Edit Grade Field"; }
	const char* GoToStodMenu() { return "Return to student menu"; }

	const char* PreSessErr() { return "Fill in previous sessions"; }
	const char* Title() { return "Item Name"; }
	
	const char* NextSubj() { return "Go to the next subject"; }
	const char* PrevSubj() { return "Go to previous item"; }
	const char* CleanGrade() { return "Clear item and grade"; }
	const char* Gr_footer() { return "If you do not fill out both assessment fields, they will not be saved"; }

	const char* Warning_header1() { return "Are you sure you want to quit?\nThe entry will not be saved"; }
	const char* Warning_header2() { return "Are you sure you want to quit?\nUnsaved data will be lost*"; }
	const char* Yes() { return "Yes, quit"; }
	const char* No() { return "No, stay"; }
};