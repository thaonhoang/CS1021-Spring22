#include <cctype>
#include <cstdio>
#include <cstdlib>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <sstream>

/*
 * format_compression_ratio
 *
 * This function will properly format _compression_ratio_ according
 * to the specifications set forth in the lab document.
 *
 * input: a double, _compression_ratio_, that is the compression ratio
 *        to format.
 * output: a std::string that contains _compression_ratio_ properly
 *         formatted according to the specifications set forth in
 *         the lab document.
 */
std::string format_compression_ratio(double compression_ratio) {
  std::stringstream formatted_ss{};
  formatted_ss << std::fixed << std::setprecision(2) << compression_ratio;
  return formatted_ss.str();
}

/*
 * data_available
 *
 * This function will determine whether there is more data to be read
 * from _file_.
 *
 * input: a std::ifstream, _file_, about which we will determine whether
 *        additional data can be read.
 * output: a bool: true if there is more data that can be read from _file_;
 *         false, otherwise.
 */
bool data_available(std::ifstream &file) {
  // std::iscntrl: Returns non-zero if the character is a control character.
  //               Flip this around logically: if the return value is 0
  //               then we know that the next character to be read is *not*
  //               a control character. 
  // EOF != file.peek(): If the next character to be read is not the end-of-file.
  return (EOF != file.peek() && 0 == std::iscntrl(file.peek()));
}
/*
* file_open
*
* This function will return true if it can open the file and false otherwise.
* 
* input: a string named filename and and ifstream named file
* 
* output: a bool, true if the file can be open, false otherwise.
*/
bool file_open(std::string filename, std::ifstream& file) {
    file.open(filename);
    return (file.is_open());
}

/*
* count_digit
* 
* This function would count the number of digit
* 
* Input: a number
* 
* Output: the number of digit it has
*/
int count_digit(int number) {
    int count = 0;
    while (number != 0) {
        number = number / 10;
        count++;
    }
    return count;
}
int main() {
    char entry_char1 {' '};
    int entry_num {0};
    char entry_char2{' '};
    int flavor{ 0 };
    int compressed_len(0);
    int compressed_len_temp;
    std::string decompress_string;
    std::ifstream rle_file;
    if (!file_open("input.rle", rle_file)) {
        std::cout << "Could not open the file containing the compressed data!\n";
        return 0;
    }
    while (data_available(rle_file)) {
        if (!(rle_file>>entry_num)) {
            std::cout << "Compressed data format error!\n";
            return 0;
        }
        if (!(rle_file >> entry_char1)) {
            std::cout << "Compressed data format error!\n";
            return 0;
        }
        else if (entry_char1 == '-') {
            if (!(rle_file >> entry_char2) ){
                std::cout << "Compressed data format error!\n";
                return 0;
            }
            else {
                flavor = 2;
            }

        }
        else {
            flavor = 1;
        }

        if (flavor == 1) {
            compressed_len_temp = count_digit(entry_num) + 1;
            for (int i = 0; i < entry_num; i++) {
                decompress_string += entry_char1;
            }
        }
        else if (flavor == 2) {
            compressed_len_temp = count_digit(entry_num) + 2;
            for (int i = 0; i < entry_num; i++) {
                decompress_string += entry_char2;
            }
        }
        compressed_len += compressed_len_temp;
    }
    double ratio;
    double origlen;
    origlen = decompress_string.length();
    ratio = origlen / compressed_len;
    std::cout << decompress_string << std::endl;
    std::cout << format_compression_ratio(ratio) << std::endl;
    return 0;
}
