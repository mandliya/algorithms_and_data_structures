/*
 * Cracking the coding interview edition *5* old one
 * 1.2  Reverse a string when you are a pass a null terminated C string.
 */


#include<iostream>
#include<cstring>
#include<generic.h>

void reverse1( char * str)
{
    int len = std::strlen(str);
    for ( int i = 0; i < len/2; ++i ) {
        algo::swap( str[i], str[len - i - 1] );
    }
}

void reverse2( char *str ) {
    if ( !str )
        return;
    char *p = str;
    char *q = str;
    while (*q) ++q;
    --q;
    //q now points to last char and p points to first char
    while ( p < q )
        std::swap( *p++, *q-- );
}

int main()
{
    char str[] = "abcdefghijklmnopqrstuvwxyz";
    reverse1(str);
    std::cout << "On reversing it once:  " << str << std::endl;
    reverse2(str); 
    std::cout << "On reversing it again: " << str << std::endl;
    return 0;
}
