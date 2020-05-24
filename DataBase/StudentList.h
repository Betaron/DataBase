#pragma once
#include <iostream>
#include "Student.h"

struct list
{
	list* previous_item;
	list* next_item;
	Student* stud;
	list() {
		previous_item = nullptr;
		next_item = nullptr;
		stud = new Student;
	}
	~list() { delete stud; }
};


class StudentList
{
private:
	list* Item_Head;
	list* Item_Current;
	uint8_t Is_Created;
	Student* list_create();
public:
	StudentList() {
		Item_Head = new list;
		Item_Current = new list;
		Is_Created = 0;
	}
	~StudentList() {
		delete Item_Head;
		delete Item_Current;
	}
	Student* item_add();
	void item_delete();
	void list_delete();
	void moveCursor(uint8_t);
	uint8_t getListStatus();

	list* GetHead() { return Item_Head; }
	list* GetItem() { return Item_Current; }
};