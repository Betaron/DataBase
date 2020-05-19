#pragma once
#include <iostream>
#include <iomanip>

using namespace std;

class Date {
private:
	uint16_t DD;
	uint16_t MM;
	uint16_t YYYY;
public:
	friend ostream& operator <<(ostream&, const Date&);
	Date() {
		DD = 0;
		MM = 0;
		YYYY = 0;
	}
	int SetDate(int, int, int);
};