#include "Date.h"

int Date::SetDate(int DD, int MM, int YYYY) {
	if (MM >= 1 && MM <= 12) this->MM = MM;
	else return 0;
	if (YYYY >= 0) this->YYYY = YYYY;
	else return 0;
	if (MM < 8) {
		if (MM % 2 == 1 && DD >= 1) {
			if (DD <= 31) this->DD = DD;
			else return 0;
		}
		if (MM % 2 == 0 && DD >= 1) {
			if (MM == 2) {
				if (YYYY % 4 != 0) {
					if (DD <= 28) this->DD = DD;
				}
				if (YYYY % 4 == 0) {
					if (DD <= 29) this->DD = DD;
				}
			}
			else if (DD <= 30) this->DD = DD;
		}
	}
	if (MM >= 8) {
		if (MM % 2 == 0 && DD >= 1)
			if (DD <= 31)
				this->DD = DD;
		if (MM % 2 == 1 && DD >= 1)
			if (DD <= 30)
				this->DD = DD;
	}
	if (this->DD == 0) return 0;
	return 1;
}

int Date::GetDay() { return DD; }
int Date::GetMonth() { return MM; }
int Date::GetYear() { return YYYY; }

ostream& operator <<(ostream& out, const Date& date) {
	out.fill('0');
	out << right << setw(2) << date.DD << '.'
		<< right << setw(2) << date.MM << '.' << right << setw(4) << date.YYYY;
	out.fill(' ');
	return out;
}

int operator !=(const Date& date1, const Date& date2) {
	if (date1.DD != date2.DD || date1.MM != date2.MM || date1.YYYY != date2.YYYY) return 1;
	else return 0;
}



int operator ==(const Date& date1, const Date& date2) {
	if (date1.DD == date2.DD && date1.MM == date2.MM && date1.YYYY == date2.YYYY) return 1;
	else return 0;
}
