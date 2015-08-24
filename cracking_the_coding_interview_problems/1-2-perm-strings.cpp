/*
 * Cracking the coding interview edition 6
 * Given two strings, determine if one is permutation of other.
 */

#include <iostream>
#include <cstring>
#include <quickSort.h>
#include <string>

/* 
 * Function: arePermutations
 * Args: string1, string2
 * return: true or false
 * assumption: ASCII char set
 */

bool arePermutations( const std::string str1, const std::string str2 )
{
    int len1 = str1.length();
    int len2 = str2.length();
    if ( len1 != len2 ) {
        return false;
    }

    int seen[128] = { 0 };

    for ( int i = 0; i < len1; ++i ) {
        seen[ int(str1[i]) ]++;
        seen[ int(str2[i]) ]--;
    }


    for ( int i = 0; i < 128; ++i ) {
        if ( seen[i] != 0 ) {
            return false;
        }
    }
    return true;
}

/* 
 * Function: arePermutations2
 * Args: string1, string2
 * return: true or false
 * assumption: ASCII char set
 */

bool arePermutations2( const std::string str1, const std::string str2 )
{
    int len1 = str1.length();
    int len2 = str2.length();
    if ( len1 != len2 ) {
        return false;
    }
    
    char *cstr1 = new char[ len1 + 1 ];
    std::strcpy( cstr1, str1.c_str() );

    char *cstr2 = new char[ len2 + 1 ];
    std::strcpy( cstr2, str2.c_str() );

    algo::quickSort( cstr1, 0, len1);
    algo::quickSort( cstr2, 0, len1);

    for (int i = 0; i < len1; ++i ) {
        if ( cstr1[i] != cstr2[i] )
            return false;
    }
    return true;
}


int main()
{
    std::string str1("abc");
    std::string str2("cba");
    std::string str3("abcd");
    std::string str4("cbad");
    std::string str5("cbcd");
    
    if ( arePermutations( str1, str2 ) ) {
        std::cout << str1 << " and " << str2 << " are permutations of each other\n";
    } else {
        std::cout << str1 << " and " << str2 << " are not permutations of each other\n";
    }

    if ( arePermutations2( str3, str4 ) ) {
        std::cout << str3 << " and " << str4 << " are permutations of each other\n";
    } else {
        std::cout << str3 << " and " << str4 << " are not permutations of each other\n";
    }

    if ( arePermutations( str2, str4 ) ) {
        std::cout << str2 << " and " << str4 << " are permutations of each other\n";
    } else {
        std::cout << str2 << " and " << str4 << " are not permutations of each other\n";
    }
    if ( arePermutations2( str4, str5 ) ) {
        std::cout << str4 << " and " << str5 << " are permutations of each other\n";
    } else {
        std::cout << str4 << " and " << str5 << " are not permutations of each other\n";
    }

    return 0;
}
