#include "Location.h"
double Location::getLatitude() const {
	return latitude;
}
double Location::getLongitude() const {
	return longitude;
}
void Location::setLatitude(double inlatitude) {
	latitude = inlatitude;
}
void Location::setLongitude(double inlongitude) {
	longitude = inlongitude;
}