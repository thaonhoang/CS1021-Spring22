#include<iostream>
/*
* This program will compute and print
* the carbon dioxide emission in 2 years and the increase 
* percentage. 
*/
int main() {
	int first_year;
	int number_first_year;
	int second_year;
	int number_second_year;
	const double CO2_per_acre{ 26.7 };
	std::cout << "Enter the first year:";
	std::cin >> first_year;
	std::cout << "Enter the acres consumed by forest fire that year:";
	std::cin >> number_first_year;
	std::cout << "Enter the second year:";
	std::cin >> second_year;
	std::cout << "Enter the acres consumed by forest fire that year:";
	std::cin >> number_second_year;
	auto first_year_emission = number_first_year * CO2_per_acre;
	auto second_year_emission = number_second_year * CO2_per_acre;
	auto percent_increase = (number_second_year - number_first_year) / static_cast<double>(number_first_year) *100;
	std::cout << "In year " << first_year << ", forest fires generated " << first_year_emission << " tons of carbon dioxide.\n";
	std::cout << "In year " << second_year << ", forest fires generated " << second_year_emission << " tons of carbon dioxide.\n";
	std::cout << "Between " << first_year << " and " << second_year << ", there was a " << percent_increase << "% increase in acres consumed by forest fires.\n";

}

