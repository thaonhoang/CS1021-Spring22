#include <iostream>
#include <fstream>
#include <string>
#include <cassert>


const int ALPHABET_LENGTH{26};

int number_from_letter(char letter) {
  int offset = letter - (int)'a';
  if (offset < 0 || offset >= ALPHABET_LENGTH) {
    std::cout << "number_from_letter called with invalid argument (" << letter << ").\n";
    assert(false);
  }
  return offset;
}

char letter_from_number(int number) {

  if (number < 0 || number >= ALPHABET_LENGTH) {
    std::cout << "letter_from_number called with an invalid argument (" << number << ").\n";
    assert(false);
  }

  const char alphabet[] = { 'a',
    'b',
    'c',
    'd',
    'e',
    'f',
    'g',
    'h',
    'i',
    'j',
    'k',
    'l',
    'm',
    'n',
    'o',
    'p',
    'q',
    'r',
    's',
    't',
    'u',
    'v',
    'w',
    'x',
    'y',
    'z'};
  return alphabet[number];
}
/*An encryption program named 1d3s
*to read in a key and plain text message
*from a file and print out the encrupted version
*/
int main() {
    std::ifstream lab4_file{ "input.txt" };
//Check if the file contains direction
    if (!lab4_file.is_open()) {
        std::cout << "Oops: Could not read the direction from the input file.\n";
        lab4_file.close();
        return 0;
    }
//If valid, take in direction and shift number, otherwise generates proper outputs.
    char shift_direction(' ');
    lab4_file >> shift_direction;
    bool continue_inputting{ true };
    if (shift_direction != 'l' && shift_direction != 'r') {
        std::cout << "Oops: Invalid direction in the input file.\n";
        lab4_file.close();
        return 0;
    }
    int shift_number{ 0 };
    if (!(lab4_file >> shift_number)) {
        std::cout << "Oops: Could not read the shift number from the input file.\n";
        lab4_file.close();
        return 0;
    }
    char c{ ' ' };
    int c_converted_number{ 0 };
    char c_converted_char{ ' ' };
// In case the shift number is bigger than 25.
    if (shift_number > 25)
        shift_number = shift_number % 26;
//Convert ciphertext character to actual character
    while (  !std::iscntrl(lab4_file.peek()) && !lab4_file.eof()) {
        lab4_file >> c;
        c_converted_number = number_from_letter(c);
        if (shift_direction == 'r') {
            c_converted_number = c_converted_number + shift_number;
            if (c_converted_number > 25) {
                c_converted_number = c_converted_number % 26;
            }
            c_converted_char = letter_from_number(c_converted_number);
        }
        else {
            c_converted_number = c_converted_number - shift_number;
            if (c_converted_number < 0) {
                c_converted_number = 26 + c_converted_number;
            }
            c_converted_char = letter_from_number(c_converted_number);
        }
        std::cout << c_converted_char; //output the actual text
    }
    std::cout << "\n";
    lab4_file.close();
    return 0;
}
