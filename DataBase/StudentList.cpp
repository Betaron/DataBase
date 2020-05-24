#include "StudentList.h"

Student* StudentList::list_create() {
	list* Item_first = new list;
	Item_first->next_item = Item_first;
	Item_first->previous_item = Item_first;
	Item_Current = Item_first;
	Item_Head->next_item = Item_first;
	Is_Created = 1;
	return Item_first->stud;
}

Student* StudentList::item_add() {
	if (Is_Created == 1) {
		list* AddedItem = new list;
		Item_Current->next_item->previous_item = AddedItem;
		AddedItem->next_item = Item_Current->next_item;
		Item_Current->next_item = AddedItem;
		AddedItem->previous_item = Item_Current;
		Item_Current = AddedItem;
		return AddedItem->stud;
	}
	else return list_create();
}

void StudentList::item_delete() {
	list* pItem;
	pItem = Item_Current;
	if (Item_Current != Item_Current->next_item) {
		Item_Current = Item_Current->previous_item;
		Item_Current->next_item = pItem->next_item;
		pItem->next_item->previous_item = Item_Current;
	}
	else {
		Item_Current = nullptr;
		Item_Head->next_item = nullptr;
		Is_Created = 0;
	}
	delete pItem;
}

void StudentList::list_delete() {
	list* pItem;
	while (Item_Head->next_item->previous_item != Item_Head->next_item) {
		pItem = Item_Head->next_item->previous_item;
		Item_Head->next_item->previous_item = Item_Head->next_item->previous_item->previous_item;
		delete pItem;
	}
	Item_Current = nullptr;
	Item_Head->next_item = nullptr;
	Is_Created = 0;
}

void StudentList::moveCursor(uint8_t direction) {
	switch (direction)
	{
	case -1:
		Item_Current = Item_Current->previous_item;
		break;
	case 1:
		Item_Current = Item_Current->next_item;
		break;
	default:
		break;
	}
}

uint8_t StudentList::getListStatus() { return Is_Created; }