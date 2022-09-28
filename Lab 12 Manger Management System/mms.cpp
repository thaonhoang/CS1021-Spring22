
#include "mms.h"
#include <string>
#include <vector>
/*
 * <inventorySize>
 *
 * This function returns the total number of adoptables in the MMS. In other words, it will return
 * the size of the adoptables member variable std::vector.
 *
 * input: none
 * output: int, This function returns the total number of adoptables in the MMS. In other words, it will 
 * return the size of the adoptables member variable std::vector.
 */
int MMS::inventorySize() const{
	return adoptables.size();
}
/*
 * <inventorySizeByShots>
 *
 * If has_shots is true, this function returns the number of adoptables in the shelter that have had their shots. If has_shots is false, 
 * this function returns the number of adoptables in the shelter that have not had their shots.
 *
 * input: has_shots: a bool that defaults to true
 * output: int
 */
int MMS::inventorySizeByShots(bool has_shots) const {
	int count = 0;
	for (auto& a : adoptables)
	{
		if (a->hasShot() == has_shots) {
			count++;
		}
	}
	return count;
}
/*
 * <inventorySizeByType>
 *
 * If type is ALL, this function returns the total number of adoptables in the MMS. For any other value of type, this function 
 * returns the number of adoptables in the MMS with that type.
 *
 * input: type: an AdoptableType that defaults to ALL.
 * output: int
 */
int MMS::inventorySizeByType(AdoptableType type) const {
	if (type == ALL) return inventorySize();
	int count = 0;
	for (auto & a : adoptables) {
		if (a->getType() == type) count++;
	}
	return count;	 
}
/*
 * <inventorySizeByRestrictions>
 *
 * If has_restrictions is true, this function returns the number of adoptables in the MMS that have adoption restrictions. If has_restrictions is false, this function returns the number of 
 * adoptables in the MMS that do not have adoption restrictions.
 *
 * input: has_restrictions: a bool that defaults to true
 * output: int
 */
int MMS::inventorySizeByRestrictions(bool has_restrictions) const {
	int count = 0;
	std::string restrict;
	for (auto& a : adoptables) {
		if (a->hasRestrictions(restrict) == has_restrictions) {
			count++;
		}
	}
	return count;
}
/*
 * <animalsInInventory	>
 *
 * This function will return a std::vector of std::strings -- one for each adoptable in the MMS. The contents of the std::strings in the std::vector will be the names of the adoptables
 * -- their first and last names separated by a space.
 *
 * input: none
 * output: std::vector<std::string>
 */
std::vector<std::string> MMS::animalsInInventory() const {
	std::vector<std::string> name;
	for (auto& a : adoptables) {
		name.push_back(a->getFirstName() + " " + a->getLastName());
	}
	return name;
}