#include "LocationDateLength.h"
#include "Date.h"
#include "Location.h"
void LocationDateLength::setLength(int inlength) {
	length = inlength;
}
int operator-(const LocationDateLength& LocationDateLength_A, const LocationDateLength& LocationDateLength_B) {
	return LocationDateLength_A.getLength() - LocationDateLength_B.getLength();
}
Date LocationDateLength::getDate() const{
	return date;
}
Location LocationDateLength::getLocation() const {
	return location;
}
int LocationDateLength::getLength() const {
	return length;
}