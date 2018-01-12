/*
 * Cracking the coding interview, edition 6
 * Problem 1.1
 * Write an algorithm to determine whether a string has unique characters or not
 * Can we do it without using additional data structures?
 */



#include <iostream>
#include <cstring>

/*
 * Function hasUniqueChars1
 * Args - std::string
 * Output:: True if string has all characters which are unique
 *          False if string has at least one repeated char.
 * Assumption:: ASCII chars, 256 chars.
 */
bool hasUniqueChars1( std::string str)
{
    int len = str.length();
    int check[8]; //represents 256 bits.
    std::memset( check, 0 , sizeof check );
    int idx, v, shift;

    for ( int i = 0; i < len; ++i) {
        v = (int) str[i];
        idx = v / 32;      //identify which int bucket will represent this char
        shift = v % 32;    //identify which bit in above int will represent the char 
        if ( check[idx] & ( 1 << shift ) ) {
            return false;
        }
        check[idx] |= ( 1 << shift );
    }
    return true;
}

/*
 * Function hasUniqueChars2
 * Args - std::string
 * Output:: True if string has all characters which are unique
 *          False if string has at least one repeated char.
 * Assumption:: string only contains (a..z), 26 chars.
 */

bool hasUniqueChars2( std::string str)
{
    int check = 0;
    int len = str.length();
    for (int i = 0; i < len; ++i)
    {
        int c = (int)(str[i] - 'a');
        if ( check & ( 1 << c ) ) {
            return false;
        }
        check |= ( 1 << c);
    }
    return true;
}


int main ()
{
    std::string word1("copyrightable");
    std::string word2("Dermatoglyphics!");
    std::string word3("abiogenesis");
    std::string word4("Centrobaric!");

    //a word with unique chars (a-z)
    std::cout << "Does " << word1 << " has unique chars :" << hasUniqueChars2(word1) << std::endl;

    //a word with unique ASCII chars
    std::cout << "Does " << word2 << " has unique chars :" << hasUniqueChars1(word2) << std::endl;

    //a word with repeated chars (a-z)
    std::cout << "Does " << word3 << " has unique chars :" << hasUniqueChars2(word3) << std::endl;
    
    //a word with repeated AsCII chars
    std::cout << "Does " << word4 << " has unique chars :" << hasUniqueChars1(word4) << std::endl;
    return 0;

}


