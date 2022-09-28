#include <iostream>
#include <string>
#include <iomanip>

/**
 * @brief Truncate a string to a certain length.
 *
 * @param value The string to truncate.
 * @param width The length to which to truncate \p value.
 * @return std::string The truncated string.
 */
std::string truncate_string(const std::string &value, int width) {
  return value.substr(0, width);
}

/**
 * @brief Get an integer from the user
 *
 * @return int The user's input, as an integer.
 */
int get_int() {
  int value{0};
  std::cin >> value;
  return value;
}

/**
 * @brief Get a string from the user.
 *
 * @return std::string The user's input, as a string.
 */
std::string get_string() {
  std::string value{""};
  std::getline(std::cin, value);
  return value;
}
const double credit_per_kWh{ 0.018 };
const double revenue_per_kWh{ 0.114951 };
const int max_company_name{ 40 };

/*calculate the total taxable revenue,
*taxable revenue per share, and print 
* a formatted tax report to the console.
*/
int main() {
/*declare and initialize variables*/
	std::string company_name{""};
	int energy_all_sources{ 0 };
	int solar_energy{ 0 };
	int wind_energy{ 0 };
	int water_energy{ 0 };
	int clean_energy{ 0 };
	int shares{ 0 };
	double revenue_before{0};
	double tax_credit{0};
	double revenue_after{ 0 };
	double revenue_per_share{0};

/*Input values and truncate the company name to the wanted length*/
	std::cout << "Enter company name: ";
	company_name = get_string();
	company_name = truncate_string(company_name, max_company_name);
	std::cout << "Enter the total energy generation (in kwH): ";
	energy_all_sources = get_int();
	std::cout << "Enter solar generation (in kwH): ";
	solar_energy = get_int();
	std::cout << "Enter wind generation (in kwH): ";
	wind_energy = get_int();
	std::cout << "Enter hydro generation (in kwH): ";
	water_energy = get_int();
	std::cout << "Enter shares outstanding: ";
	shares = get_int();
/*Compute the revenue calculate the total the company's total revenue from energy production/distribution,
*calculate the company's tax credits,
*calculate the company's total tax bill,
* and total calculate the company's tax bill per outstanding share*/
	revenue_before = energy_all_sources * revenue_per_kWh;
	clean_energy += solar_energy;
	clean_energy += wind_energy;
	clean_energy += water_energy;
	tax_credit = static_cast<double>(clean_energy) * credit_per_kWh ;
	revenue_after = revenue_before - tax_credit;
	revenue_per_share = revenue_after / static_cast<double>(shares);
/*Present output to the console*/
	std::cout << "Revenue Per Share Report Generator\n";
	std::cout << std::setfill('=') << std::setw(80) << "" << "\n";
	std::cout << std::setfill(' ') << std::setw(40) << std::left << "Prepared For: " << std::setw(40) << std::right << company_name << "\n";
	std::cout << std::setfill(' ') << std::setw(40) << std::left << "Taxable Total Revenue:" << std::setw(40) << std::right << std::fixed << std::setprecision(2) << revenue_after << "\n";
	std::cout << std::setfill(' ') << std::setw(40) << std::left << "Taxable Revenue Per Share:" << std::setw(40) <<std::right << std::fixed << std::setprecision(2) << revenue_per_share << "\n";
	std::cout << std::setfill('=') << std::setw(80) << "" << "\n";

	
	return 0;
}
