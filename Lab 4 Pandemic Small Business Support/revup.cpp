#include <string.h>

#include <cstdlib>
#include <iomanip>
#include <ios>
#include <iostream>
#include <sstream>

std::string intended_use{""};
double requested_loan_amt{0.0};
bool non_profit_business{false};

void get_input(int argc, char **argv) {
  if (argc == 1) {
    intended_use = "debt";
    requested_loan_amt = 25000.0;
    non_profit_business = true;
  } else if (argc == 4) {
    // The first CLI parameter is the intended use for the loan.
    intended_use = argv[1];

    // NB: No error checking is done here. User must be careful to only
    // pass valid numbers!
    requested_loan_amt = static_cast<double>(atoi(argv[2]));

    // The final CLI parameter is whether the applicant's business is
    // a non-profit. If the parameter is "true", then the business is
    // a non-profit.
    if (!strcmp("true", argv[3])) {
      non_profit_business = true;
    }
  } else {
    exit(EXIT_FAILURE);
  }
}

void print_horizontal_line(int columns) {
  auto flags = std::cout.flags();
  auto fill = std::cout.fill();
  std::cout << std::setfill('=') << std::setw(columns) << ""
            << "\n";
  std::cout.flags(flags);
  std::cout.fill(fill);
}

std::string format_money(double money) {
  std::stringstream formatted_money{};
  formatted_money << std::fixed << std::setprecision(2) << std::showpoint;
  formatted_money << "$" << money;
  return formatted_money.str();
}

std::string format_percentage(double percentage) {
  std::stringstream formatted_percentage{};
  formatted_percentage << std::fixed << std::setprecision(2) << std::showpoint;
  formatted_percentage << percentage << "%";
  return formatted_percentage.str();
}
//The bool_to_yes_no function would output either
//Yes or No according to the parameter being true or
//not. The parameter that it accepts is a boolean value
//with true and false being the only valid values. The 
//return value has a string data type, being either yes if 
//if the boolean value equals true and no if the boolean 
//value equals false.
std::string bool_to_yes_no(bool value) {
  std::string yes_no{""};
  if (value) {
    yes_no = std::string{"Yes"};
  } else {
    yes_no = std::string{"No"};
  }
  return yes_no;
}

void print_labeled_value(const std::string &label, int label_width,
                         const std::string &value, int value_width) {
  auto flags = std::cout.flags();
  auto fill = std::cout.fill();
  std::cout << std::setfill(' ') << std::left << std::setw(label_width) << label
            << std::right << std::setw(value_width) << value << "\n";
  std::cout.flags(flags);
  std::cout.fill(fill);
}
/*The purpose of this program is to calculate
*whether the the business is qualified for a loan.
* If eligible, it would also compute interest rate,
* fees associated, collateral and personal guaranty
* requirement
*/
const double NON_PROFIT_INTEREST_RATE = 2.75;
const double FOR_PROFIT_INTEREST_RATE = 3.75;
int main(int argc, char **argv) {
  get_input(argc, argv);

  // Complete the implementation of main according to the specifications in the
  // lab document! Do not remove any code that exists. Simply add additional
  // code to meet the description of RevUp's operation.
  double interest_rate{0};
  int apply_fee{0};
  std::string collateral_fee{""};
  std::string personal_guaranty{""};
  print_horizontal_line(80);
  if (intended_use == "mortgage" || intended_use == "payroll" ||
      intended_use == "rent" || intended_use == "utilities" ||
      intended_use == "debt" || intended_use == "ordinary business expenses") {
    if (requested_loan_amt <= 2000000) {
      print_labeled_value("Eligibility Status:", 40, "Yes", 40);
      if (non_profit_business) {
        interest_rate = NON_PROFIT_INTEREST_RATE;
      }
      else {
        interest_rate = FOR_PROFIT_INTEREST_RATE;
      }
      print_labeled_value("Interest Rate:", 40, format_percentage(interest_rate), 40);
      if (requested_loan_amt>25000){
        apply_fee = 100;

    } else {
        apply_fee = 0;
      }
    print_labeled_value("Application Fee:", 40, format_money(apply_fee), 40);
      if (requested_loan_amt > 25000) {
        collateral_fee = "Yes";
    } 
      else{
        collateral_fee = "No";    
    }
      print_labeled_value("Collateral Required:", 40, collateral_fee, 40);
      if (requested_loan_amt > 200000) {
        personal_guaranty = "Yes";

    } 
      else {
        personal_guaranty = "No";
      }
    print_labeled_value("Personal Guaranty: ", 40, personal_guaranty, 40);
    } 
    else {
      print_labeled_value("Eligibility Status:", 40, "No", 40);
    }
    
  } 
  else {
    print_labeled_value("Eligibility Status:", 40, "No", 40);
  }
  print_horizontal_line(80);
  return 0;
}
