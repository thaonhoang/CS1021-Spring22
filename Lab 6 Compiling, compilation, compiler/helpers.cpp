#include <cassert>
#include <ios>
#include <iostream>
#include <string>

/*
 * is_vowel
 *
 *
 * input: a character
 * output: a boolean, returns true if input is a vowel and false otherwise
 *          
 */
bool is_vowel(char c) {
	if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u'){
		return true;
	}
	else {
		return false;
	}
}

/*
 * is_consonant
 *
 * returns true when its argument is a consonant and false otherwise
 *
 * input: a character
 * output: a boolean, returns true if input is a consonant and false otherwise
 *
 */
bool is_consonant(char p) {
	if (is_vowel(p) == false){
		return true;
	}
	else {
		return false;
	}
}

/*
 * ends_with
 *
 * if candidate is an empty string and suffix is an empty string, ends_with 
 *returns true. If candidate is an empty string and suffix is not an empty 
 *string, ends_with returns false. If candidate ends with suffix, ends_with 
 *returns true. Otherwise, it returns false.
 *
 * input: two strings, candidate and suffix (in that order).
 * output: a bool, true if both strings are empty, if candidate is empty and
 * suffix is not, returns false. If candidate ends with suffix, ends with returns
 * true. Otherwise, false.
 *
 */
bool ends_with(std::string candidate, std::string suffix) {
	if (candidate.length() < suffix.length()) {
		return false;
	}
	else if (candidate == "" && suffix == "") {
		return true;
	}
	int index{ 0 };
	for (int i = (suffix.length() - 1); i >= 0; i--) {
		if (candidate.at(i+candidate.length()-suffix.length()) == suffix.at(i)) {
			index += 1;
		}
	}
	if (index == suffix.length()) {
		return true;
	}
	else {
		return false;
	}
}

/*
 * ends_with_double_consonant
 *
 * returns true if the last two characters of the argument are
 *both consonants, and
 *equal to one another.It returns false otherwise.
 *
 * input: a string
 * output: a bool, true if the last two characters are both consonants and equal, false
 * otherwise.
 *
 */
bool ends_with_double_consonant(std::string p) {
	if (p.length() < 2){
		return false;
	}
	if (is_consonant(p.at(p.length()-1))==true && is_consonant(p.at(p.length() - 2))==true && (p.at(p.length()-2) == p.at(p.length() - 1))) {
		return true;
	}
	else {
		return false;
	}
}

/*
 *ends_with_double_consonant
 *
 *returns true if the last three characters of the argument are a consonant, a vowel 
 *and then a consonant (hence the name, cvc). It returns false otherwise.
 * 
 *input: a string
 *output: a bool, returns true if the last three characters of the argument are a consonant,
 a vowel and then a consonant (hence the name, cvc). It returns false otherwise.
 */

bool ends_with_cvc(std::string q) {
	if (q.length() < 3){
		return false;
	}
	if (is_consonant(q.at(q.length() - 3))==true && is_vowel(q.at(q.length() - 2))==true && is_consonant(q.at(q.length()-1))==true) {
		return true;
	}
	else {
		return false;
	}
}

/*
 * count_consonants_at_front
 *
 *count_consonants_at_front returns the number of consecutive constants at the
 *beginning of the argument. For example, count_consonants_at_front(std::string{"threw"})
 *is 3.
 *
 * input: a string
 * output: an int, returns the number of consecutive consonants at the beginning.
 *
 */
int count_consonants_at_front(std::string w) {
	int count{ 0 };
	if (w.length() == 0) {
		return count;
	}
	else {
		for (int i = 0; i < w.length(); i++) {
			if (is_consonant(w.at(i))==true) {
				count += 1;
			}
			else {
				break;
			}
		}
		return count;
	}
	
}

/*
 * count_vowels_at_back
 *
 *count_vowels_at_back returns the number of consecutive constants at the
 *end of the argument. 
 *
 * input: a string
 * output: an int, returns the number of consecutive vowels at the end.
 *
 */
int count_vowels_at_back(std::string m) {
	int countv{ 0 };
	if (m.length() == 0) {
		return countv;
	}
	else {
		for (int i = (m.length()-1); i >=0; i--) {
			if (is_vowel(m.at(i))==true) {
				countv += 1;

			}
			else {
				break;
			}
		}
		return countv;
	}
}


/*
 * contains_vowel
 *
 *contains_vowel returns true if there is a vowel anywhere in the argument. 
 *It returns false otherwise.
 *
 * input: a string
 * output: a bool, returns true if there is a vowel, false otherwise.
 *
 */
bool contains_vowel(std::string n) {
	int vowCount{ 0 };
	if (n.length() == 0) {
		return vowCount;
	}
	else {
		for (int i = 0; i < n.length(); i++) {
			if (is_vowel(n.at(i))==true) {
				vowCount += 1;
				if (vowCount!= 0) {
					break;
				}
			}
			}
			if (vowCount!=0) {
				return true;
			}
			else {
				return false;
		}
	}

}


/*
 * new_ending
 *
 * new_ending creates a new string from candidate by removing its last suffix length characters and 
 * replacing them with replacement. new_ending returns that new string.
 *
 * input: a string
 * output: a string that has already been replaced according to wanted.
 *
 */
std::string new_ending(std::string candidate, int suffix_length, std::string replacement) {
	candidate.replace(candidate.length() - suffix_length, suffix_length, replacement);
	return candidate;

}

