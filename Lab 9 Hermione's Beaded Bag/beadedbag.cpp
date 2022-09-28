#include <algorithm>
#include "beadedbag.h"
#include "item.h"
#include <vector>

// Implement the BeadedBag::size and BeadedBag::insert member functions here.

// Complete the implementation of the BeadedBag::contains member function.
/*
 * <bool contains(Item maybe_contained_item);>
 *
 * This function will return true if maybe_contained_item is already present in the Beaded Bag; it will return false otherwise.
 *
 * input: < an item>
 * output: return true if maybe_contained_item is already present in the Beaded Bag; it will return false otherwise.
 */
bool BeadedBag::contains(Item maybe_contained_item) {
	for (int i = 0; i < bag.size(); i++) {
		if (maybe_contained_item.isEqual(bag.at(i))) {
			return true;
		}
	}
	return false;
}

/*
 *
 * <void insert(Item to_insert);>
 *
 * input: item to_insert
 * output: insert to_insert into the Beaded Bag as long as it is not already present.
 */
void BeadedBag::insert(Item to_insert) {
	if (!contains(to_insert)) {
		bag.push_back(to_insert);
	}
}

/*
 * <int size();>
 *
 * <This function will return the number of Items in the Beaded Bag.>
 *
 * output: an integer that shows the number of items in the bag
 */
int BeadedBag::size() {
	return bag.size();
  
}