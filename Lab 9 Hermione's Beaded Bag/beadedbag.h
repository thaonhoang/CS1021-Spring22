#ifndef __BEADEDBAG_BEADEDBAG_HPP
#define __BEADEDBAG_BEADEDBAG_HPP

#include "item.h"
#include <vector>

class BeadedBag {
public:
  // Place your member function declarations here.

  // Here's the declaration for contains, to get you started:
/*
 * <bool contains(Item maybe_contained_item);>
 *
 * This function will return true if maybe_contained_item is already present in the Beaded Bag; it will return false otherwise.
 *
 * input: < an item>
 * output: return true if maybe_contained_item is already present in the Beaded Bag; it will return false otherwise.
 */
  bool contains(Item maybe_contained_item);

  /*
   *
   * <void insert(Item to_insert);>
   *
   * input: item to_insert
   * output: insert to_insert into the Beaded Bag as long as it is not already present.
   */
  void insert(Item to_insert);

  /*
   * <int size();>
   *
   * <This function will return the number of Items in the Beaded Bag.>
   *
   * output: an integer that shows the number of items in the bag
   */
  int size();

private:
	std::vector<Item> bag;
};

#endif