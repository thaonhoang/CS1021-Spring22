#include "adoptable.h"
#include <string>
/*
* <hasRestrictions>
*
* <A bool. true if there are restrictions; false, otherwise.>
*
* input: <(out) restrictions: a std::string that the function
* populates with the adoption restrictions for this adoptable.>
* output: true if there are restrictions; false, otherwise.
*/
bool Adoptable::hasRestrictions(std::string &restrictions) { return false; }
/*
 * <getType>
 *
 * <If this method is invoked on an instance of a Dog adoptable, then the return value is DOG. If this method is invoked on an instance of a Cat adoptable, then the return value is CAT. If this method is invoked on an instance
 * of a Turtle adoptable, then the return value is TURTLE. >
 *
 * input: none
 * output: An AdoptableType.
 */
AdoptableType Adoptable::getType() const {
    return adoptable_type;
}
/*
 * <hasShot>
 *
 * If the adoptable has had their shots, the function returns true.
 * Otherwise, the function returns false.
 *
 * input: none
 * output: a bool
 */
bool Adoptable::hasShot() const {
    return has_shots;
}
/*
 * getFirstName
 *
 * The function returns the first name of the adoptable.
 *
 * input: none
 * output: a std::string
 */
std::string Adoptable::getFirstName() const {
    return first_name;
}
/*
 * getLastName
 *
 * The function returns the last name of the adoptable.
 *
 * input: none
 * output: a std::string
 */
std::string Adoptable::getLastName() const {
    return last_name;
}

void Adoptable::print() {
  std::string restrictions{""};
  std::cout << "First name: " << first_name << "\n";
  std::cout << "Last name: " << last_name << "\n";
  std::cout << "Has Shots?: " << (has_shots ? "Yes" : "No") << "\n";
  std::cout << "Adoptable Since: " << adoptable_since << "\n";
  if (hasRestrictions(restrictions)) {
    std::cout << "Restrictions: " << restrictions << "\n";
  }
}


bool Turtle::hasRestrictions(std::string& restrictions) {
    restrictions = "Adopter must be at least 21 years old.";
    return true;
}
