#ifndef LOCATIONDATELENGTH_H
#define LOCATIONDATELENGTH_H

#include "Date.h"
#include "Location.h"

class LocationDateLength {
	public:
		LocationDateLength() {};
		LocationDateLength(Date d_obj, Location l_obj)
		{
			location = l_obj;
			date = d_obj;
		}
		friend int operator-(const LocationDateLength& LocationDateLength_A, const LocationDateLength& LocationDateLength_B);

		Date getDate() const;
		Location getLocation() const;
		int getLength() const;
		void setLength(int length);
	private:
		Date date;
		Location location;
		int length;
};
#endif
