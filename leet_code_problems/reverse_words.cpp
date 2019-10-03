/*
 * Given a string, you need to reverse the order of characters in each word within a sentence
 *  while still preserving whitespace and initial word order.
 * 
 * Example:
 * Input:  She loves    chocolate 
 * Output: ehs sevol    etalocohc
 * 
 * Approach:
 * Use two indices to figure out non-whitespace characters, and reverse
 * the portion.
 */

#include <iostream>
#include <string>


std::string reverse_words(std::string& sentence)
{
    for(int i = 0; i < sentence.length(); ++i) {
        if (sentence[i] != ' ') {
            int j = i;
            // let j find the end of non-whitespace portion
            while (j < sentence.length() &&
                sentence[j] != ' ') {
                j++;
            }
            std::reverse(sentence.begin() + i, sentence.begin() + j);
            // reset i to next word.
            i = j - 1;
        } 
    }
    return sentence;
}

int main()
{
    std::string sentence{"She loves    chocolate"};
    std::cout << "Input:  " << sentence << std::endl;
    std::cout << "Output: " << reverse_words(sentence) << std::endl;
    return 0; 
}