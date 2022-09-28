#ifndef __BEADEDBAG_ITEM_HPP
#define __BEADEDBAG_ITEM_HPP

#include <string>

class Item {
public:
  Item(const std::string &item_name);
  /*
 * <std::string getName>
 *
 * This member function will return the m_name of the Item.
 *
 * input: a string
 * output: return the m_name of the Item.
 */
  std::string getName();

 /*
  * <bool isEqual(Item other);>
  *
  *  This member function returns true if other's m_name is equal to this Item's m_name.
  *
  * input: a string
  * output: true if other's m_name is equal to this Item's m_name.
 */
  bool isEqual(Item other);

private:
  std::string m_name;
};

#endif