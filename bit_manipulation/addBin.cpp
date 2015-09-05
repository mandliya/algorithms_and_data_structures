/*
 * Add two binary numbers represented as string.
 *
 */
#include <iostream>
#include <string>
#include <sstream>
#include <algorithm>

std::string addBinary( const std::string & str1, const std::string & str2 )
{
    std::string s1 = ( str1.length() > str2.length() ? str1 : str2 );
    std::string s2 = ( str1.length() > str2.length() ? str2 : str1 );
    int diff = s1.length() - s2.length();
    std::stringstream ss;
    while(diff) {
        ss << "0";
        --diff;
    }
    s2 = ss.str() + s2;
    std::cout << s1 << std::endl;
    std::cout << s2 << std::endl;
    ss.str(std::string());
    int i = s1.length() - 1;
    int carry = 0;
    while ( i >= 0 ) {
        int x = ( s1[i] - '0') + ( s2[i] - '0') + carry;
        if ( x == 2 ) {
            x = 0;
            carry = 1;
        } 
        else if ( x == 3 ) {
            x = 1;
            carry = 1;
        } else {
            carry = 0;
        }
        ss << x;
        --i;
    }
    if ( carry == 1 )
        ss << carry;

    std::string result = ss.str();
    std::reverse(result.begin(), result.end());
    return result;

}

int main()
{
    std::string str1("1010");
    std::string str2("1011");
    std::cout << "Addition of " << str1 << " and " << str2 << " is :" << addBinary(str1, str2) << std::endl;
    return 0;

}
