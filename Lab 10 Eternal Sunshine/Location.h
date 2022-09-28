#ifndef LOCATION_CPP
#define LOCATION_CPP
class Location {
	public:
		Location() {};
		double getLatitude() const;
		double getLongitude() const;
		void setLatitude(double inlatitude);
		void setLongitude(double inlongtitude);
	private:
		double longitude;
		double latitude;

};

#endif
