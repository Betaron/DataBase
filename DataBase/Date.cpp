#include "Date.h"

int Date::SetDate(int DD, int MM, int YYYY) {
	if (MM >= 1 && MM <= 12) this->MM = MM;
	else return 1;
	if (YYYY >= 0) this->YYYY = YYYY;
	else return 1;
	if (MM % 2 == 1 && DD >= 1) {
		if (DD <= 31) this->DD = DD;
		else return 1;
	}
	if (MM % 2 == 0 && DD >= 1) {
		if (MM == 2) {
			if (YYYY % 4 != 0) {
				if (DD <= 28) this->DD = DD;
			}
			if (YYYY % 4 == 0)
				if (DD <= 29) this->DD = DD;
		}
		else if (DD <= 30) this->DD = DD;
	}
	if (this->DD == 0) return 1;
	return 0;
}

ostream& operator <<(ostream& out, const Date& date) {
	out.fill('0');
	out << setw(2) << date.DD << '.'
		<< setw(2) << date.MM << '.' << setw(4) << date.YYYY;
	return out;
}