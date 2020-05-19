#pragma once

#define NaN return "NaN"

using namespace	std;

class phrases {
protected:
	string str;
public:
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
	virtual const char* Task44() { NaN; }
	virtual const char* DBmenu_footer() { NaN; }
};

class rus: public phrases{
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
		this->str = "База данных: " + DBname;
		return this->str.c_str();
	}
	const char* ShowDB() { return "Показать базу данных"; }
	const char* AddEntry() { return "Добавить новую запись"; }
	virtual const char* Task44() { return "Задание варианта - 44"; }
	virtual const char* DBmenu_footer() {
		return "Для редактирования или удаления используйте:\n'Показать базу данных'.\nВам необходимо выбрать студента в списке";
	}
};

class eng: public phrases {
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
		this->str = "Database: " + DBname;
		return this->str.c_str();
	}
	const char* ShowDB() { return "Show database"; }
	const char* AddEntry() { return "Add New Entry"; }
	virtual const char* Task44() { return "Task of variant - 44"; }
	virtual const char* DBmenu_footer() {
		return "To edit or delete use:\n'Show database'.\nYou must select a student in the list.";
	}
};