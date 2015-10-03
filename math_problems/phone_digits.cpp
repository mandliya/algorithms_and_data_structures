/**
 * Given a normal keypad.
 * _________________________
 * |   1   |   2   |   3   |
 * |       |  abc  |  def  |
 * _________________________
 * |   4   |   5   |   6   |
 * |  ghi  |  jkl  |  mno  |
 * ________________________
 * |  7    |   8   |   9   |
 * |  pqrs |  tuv  | wxyz  |
 * _________________________
 * 
 * and a n digit number, list all the words which are possible by pressing these n digits.
 * example
 * 234 - adg adh adi aeg aeh aei afg afh afi bdg bdh bdi beg beh bei bfg bfh bfi
 *       cdg cdh cdi ceg ceh cei cfg cfh cfi
 */

#include <iostream>
#include <string>
#include <unordered_map>
#include <sstream>
#include <vector>

std::unordered_map<char, std::string> table{ { '0', "" },
                                             { '1', "" },
                                             { '2', "abc"},
                                             { '3', "def"},
                                             { '4', "ghi"},
                                             { '5', "jkl"},
                                             { '6', "mno"},
                                             { '7', "pqrs"},
                                             { '8', "tuv"},
                                             { '9', "wxyz"} };


void get_words( std::string input, unsigned int curr_digit,
                std::stringstream & ss, std::vector<std::string> &  output)
{
    if ( curr_digit == input.size() - 1 ) {
        output.push_back(ss.str());
        return;
    }
    std::string curr_alphas{ table[input[curr_digit]] };
    for( unsigned int i = 0; i < curr_alphas.size(); ++i ) {
        ss << curr_alphas[i];
        get_words( input, curr_digit + 1, ss, output);
        if (curr_alphas[i] == '0' || curr_alphas[i] == '1') {
            return;
        }
    }
}

int main()
{
    std::string input;
    std::cout << "Enter a number:";
    std::cin >> input;
    std::stringstream ss;
    std::vector<std::string> output;
    get_words(input, 0, ss, output);
    for ( auto & word : output ) {
        std::cout << word << std::endl;
    }
    return 0;
}
