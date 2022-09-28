#ifndef DATE_HPP
#define DATE_HPP

#include <iostream>
class Date {
	public:
		Date() {};
		void setDay(int inday);
		void setMonth(int inmonth);
		void setYear(int inyear);
		int getDay() const;
		int getMonth() const;
		int getYear() const;
	private:
		int day;
		int month;
		int year;
};
std::ostream& operator<<(std::ostream& os, const Date& dt);
#endif
