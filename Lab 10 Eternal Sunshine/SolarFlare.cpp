#include "httplib.h"
#include "json.hpp"
#include <cassert>
#include <cmath>
#include <fstream>
#include <ios>
#include <iostream>
#include <memory>

#include "Date.h"
#include "Location.h"
#include "LocationDateLength.h"

#define assert_with_message(condition, message)                                \
  if (!(condition)) {                                                          \
    assert((message, (condition)));                                            \
  }

/*
 * parse_json_daylength_response
 *
 * This function parses the JSON response from the Sunrise Sunset
 * Web API and replaces the length in the member of the first
 * parameter with the value embedded in the JSON.
 *
 * input: _raw_json_: The resulting data, as a std::string,
 *         of the Sunrise Sunset WebAPI call.
 * output: _day_length_response: A std::unique_ptr to a
 *         LocationDateLength struct whose length member is updated
 *         to match the daylength embedded in the 1st parameter.
 * return: A bool: true if the content downloaded from the Sunrise
 *         Sunset API was properly formatted; false otherwise.
 */
bool parse_json_daylength_response(std::string raw_json,
                                   LocationDateLength &day_length_response) {
  using nlohmann::json;
  try {
    auto parsed_json = json::parse(raw_json);
    auto iso_time{parsed_json["results"]["day_length"].get<int>()};

    day_length_response.setLength(iso_time);
    return true;
  } catch (json::parse_error &e) {
    /*
     * There was a parsing error.
     */
    return false;
  }
}

/*
 * download
 *
 * This function will use HTTP to connect to the server, issue the
 * Web API call and download the server's response. In the case of
 * an error, the function will return false. Otherwise, the function
 * will return true.
 *
 * input: _host_: The name of the server from which to download.
 *        _path_: The path of the Web API.
 * output: _content_: The content of the Web API call's response.
 * return: A bool: true if the Web API was properly invoked; false, otherwise.
 */
bool download(std::string host, std::string path, std::string &content) {
  auto client = httplib::Client(host);

  auto result = client.Get(path.c_str());

  if (result && result->status == 200) {
    content = result->body;
    return true;
  } else {
    return false;
  }
}

/*
 * build_url_path
 *
 * The function will use the values in the LocationDateLength
 * C++ struct given as a parameter to create a properly-formatted WebAPI
 * query for the Sunrise Sunset API. The struct must contain valid values
 * for the date and the location. The resulting std::string can be used
 * as an argument to the download function.
 *
 * input: _daylength_: The date and location for which to request the
 *        daylength from the Sunrise Sunset Web API.
 * return: A std::string that contains the properly-formatted path of the
 *         Sunrise Sunset WebAPI request for the given date and location.
 */
std::string build_url_path(LocationDateLength &daylength) {
  assert_with_message(
      daylength.getDate().getDay() > 0 && daylength.getDate().getDay() < 32 &&
          daylength.getDate().getYear() > 999 &&
          daylength.getDate().getYear() < 3000 &&
          daylength.getDate().getMonth() > 0 &&
          daylength.getDate().getMonth() < 12,
      std::string{"Date parameters in the argument appear to be invalid."});
  assert_with_message(
      std::abs(daylength.getLocation().getLatitude()) < 180.0 &&
          std::abs(daylength.getLocation().getLongitude()) < 180.0,
      std::string{"Location parameters in argument appear to be invalid."});

  std::stringstream url_path_stream{""};
  url_path_stream << "/json?formatted=0&lat="
                  << daylength.getLocation().getLatitude()
                  << "&lng=" << daylength.getLocation().getLongitude()
                  << "&date=" << daylength.getDate().getYear() << "-"
                  << daylength.getDate().getMonth() << "-"
                  << daylength.getDate().getDay();
  return url_path_stream.str();
}
const double CINCY_LATITUDE{ 39.103119 };
const double CINCY_LONGITUDE{ -84.512016 };
int main() {

    int date1;
    int month1;
    int year1;
    int date2;
    int month2;
    int year2;
    char dash {' '};
    std::string empty{ "" };
    std::ifstream input_file{ "query_file.txt" };
    if (!(input_file >> year1 && input_file >> dash && input_file >> month1 && input_file >> dash && input_file >> date1)) {
        std::cout << "Oops: Could not read two valid dates from file.\n";
        return 0;
    }
    if (!(input_file >> year2 && input_file >> dash && input_file >> month2 && input_file >> dash && input_file >> date2)) {
        std::cout << "Oops: Could not read two valid dates from file.\n";
        return 0;
    }
    Date Date_1;
    Date Date_2;
    Date_1.setDay(date1);
    Date_1.setMonth(month1);
    Date_1.setYear(year1);
    Date_2.setDay(date2);
    Date_2.setMonth(month2);
    Date_2.setYear(year2);
    Location Location_1;
    Location Location_2;
    Location_1.setLatitude(CINCY_LATITUDE);
    Location_1.setLongitude(CINCY_LONGITUDE);
    Location_2.setLatitude(CINCY_LATITUDE);
    Location_2.setLongitude(CINCY_LONGITUDE);
    LocationDateLength LocationDateLength_1(Date_1, Location_1);
    LocationDateLength LocationDateLength_2(Date_2, Location_2);
    std::string urlPath1 = build_url_path(LocationDateLength_1);
    if (urlPath1 == empty) {
        std::cout << "Oops: There was a Web API error.\n";
        return 0;
    }
    std::string urlPath2 = build_url_path(LocationDateLength_2);
    if (urlPath2 == empty) {
        std::cout << "Oops: There was a Web API error.\n";
        return 0;
    }
    std::string Result1;
    if (download("api.sunrise-sunset.org", urlPath1, Result1) == false) {
        std::cout << "Oops: There was a Web API error.\n";
        return 0;
    }
    std::string Result2;
    if (download("api.sunrise-sunset.org", urlPath2, Result2) == false) {
        std::cout << "Oops: There was a Web API error.\n";
        return 0;
    }
    if (parse_json_daylength_response(Result1, LocationDateLength_1) == false) {
        std::cout << "Oops: There was a Web API error.\n";
        return 0;
    }
    if (parse_json_daylength_response(Result2, LocationDateLength_2) == false) {
        std::cout << "Oops: There was a Web API error.\n";
        return 0;
    }
    std::string comparison{ "" };
    int length_difference = LocationDateLength_1 - LocationDateLength_2;
    if (length_difference < 0) {
        comparison = "longer";
    }
    else {
        comparison = "shorter";
    }
    int second = abs(length_difference % 60);
    int minute = abs(length_difference / 60);
    int hour = abs(minute / 60);
    minute = abs(minute % 60);

    std::cout << Date_2 << " was " << hour << " hour(s), " << minute << " minute(s) and " << second << " second(s) " << comparison << " than " << Date_1 << ".\n";
    return 0;
}
