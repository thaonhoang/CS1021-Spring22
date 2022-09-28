#include "Date.h"
#include <iostream>
void Date::setDay(int inday) {
	day = inday;
}
void Date::setMonth(int inmonth) {
	month = inmonth;
}
void Date::setYear(int inyear) {
	year = inyear;
}
int Date::getDay() const {
	return day;
}
int Date::getMonth() const {
	return month;
}
int Date::getYear() const {
	return year;
}

std::ostream& operator<<(std::ostream& os, const Date& dt)
{
	os << dt.getYear() << '-' << dt.getMonth() << '-' << dt.getDay();
	return os;
}
