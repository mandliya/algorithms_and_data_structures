/*
 * Cracking the coding interview, edition 5
 * Problem 1.3
 * Write an algorithm to remove duplicate chars from a string
 */


#include <iostream>
#include <cstring>

using std::string;
using std::cin;
using std::cout;
using std::endl;

/*
 * Function - removeDuplicates1
 * Args     - A string 
 * Return   - Arg string with no duplicate chars
 * Runtime  - O(n)
 * Assumption - contains letter ( a - z )
 */

string removeDuplicates1( const string & str )
{
    int len = str.length();
    if ( len < 2 ) {
        return str;
    }
    int check = 0;
    string result("");
    for ( auto & ch : str ) {
        int c = (int)( ch - 'a');
        if ( (check & ( 1 << c )) == 0) {
            result += ch;
            check |= ( 1 << c);
        }
    }
    return result;
}

/*
 * Function - removeDuplicates2
 * Args     - A string 
 * Return   - Arg string with no duplicate chars
 * Runtime  - O(n)
 * Assumption - ASCII extended char set
 */

string removeDuplicates2 ( const string & str )
{
    int len = str.length();
    if ( len < 2 )
        return str;
    string result("");
    bool check[256];
    for ( auto & ch : str ) {
        if ( !check[(int)ch] ) {
            check[(int)ch] = true;
            result += ch;
        }
    }
    return result;
}



/*
 * Function - removeDuplicates3
 * Args     - A string 
 * Return   - Arg string with no duplicate chars
 * Runtime  - O(n^2)
 * Assumption - NONE
 */

string removeDuplicates3( string str )
{
    int len = str.length();
    if ( len < 2 ) {
        return str;
    }
    string result("");
    for ( int i = 0; i < len; ++i) {
        if ( str[i] != '\0' ) {
            result += str[i];
            for ( int j = i + 1; j < len; ++j ) {
                if ( str[i] == str[j] ) {
                    str[j] = '\0';
                }
            }
        }
    }
    return result;
}




/*
 * Function - removeDuplicates4
 * Args     - A C string 
 * Return   - void, we change the char array we pass as arg
 * Runtime  - O(n)
 * Assumption - contains letter ( a - z )
 */

void removeDuplicates4( char * str )
{
    int len = std::strlen(str);
    if ( len < 2) {
        return;
    }
    int check = 0;
    int cindx = 0;
    for ( int i = 0; i < len; ++i) {
        int c = (int) ( str[i] - 'a');
        if ( (check & ( 1 << c )) == 0 ) {
            str[cindx++] = str[i];
            check |= ( 1 << c );
        }
    }
    str[cindx] = '\0';
}

/*
 * Function - removeDuplicates5
 * Args     - A c string 
 * Return   - void, we change the c-string we pass to function
 * Runtime  - O(n^2)
 * Assumption - NONE
 */

void  removeDuplicates5( char * str )
{
    int len = std::strlen(str);
    if ( len < 2 ) {
        return;
    }
    int idx = 0;
    for ( int i = 0; i < len; ++i) {
        if ( str[i] != '\0' ) {
            str[idx++] = str[i];
            for ( int j = i + 1; j < len; ++j ) {
                if ( str[i] == str[j] ) {
                    str[j] = '\0';
                }
            }
        }
    }
}


/*
 * Function - removeDuplicates6
 * Args     - A c string 
 * Return   - void, we change the c-string we pass to function
 * Runtime  - O(n)
 * Assumption - ASCII extended char set
 */

void removeDuplicates6 ( char *str )
{
    int len = std::strlen(str);
    if ( len < 2 )
        return;
    bool check[256] = {false};
    int idx = 0;
    for ( int i = 0; i < len; ++i )
    {
        if ( !check[(int)str[i]] ) {
            check[(int)str[i]] = true;
            str[idx++] = str[i];
        }
    }
    str[idx] = '\0';
}

int main()
{
    string str1("aaaabbbbbcddeffgheee");
    string str2("abcd");
    string str3("a");
    string str4("");
    cout << "For method 1:" << endl;
    cout << "original-string:" << str1 << " after removing duplicates:" <<  removeDuplicates1(str1) << endl;
    cout << "original-string:" << str2 << " after removing duplicates:" <<  removeDuplicates1(str2) << endl;
    cout << "original-string:" << str3 << " after removing duplicates:" <<  removeDuplicates1(str3) << endl;
    cout << "original-string:" << str4 << " after removing duplicates:" <<  removeDuplicates1(str4) << endl;


    cout << "\n\nFor method 2:" << endl;
    cout << "original-string:" << str1 << " after removing duplicates:" <<  removeDuplicates2(str1) << endl;
    cout << "original-string:" << str2 << " after removing duplicates:" <<  removeDuplicates2(str2) << endl;
    cout << "original-string:" << str3 << " after removing duplicates:" <<  removeDuplicates2(str3) << endl;
    cout << "original-string:" << str4 << " after removing duplicates:" <<  removeDuplicates2(str4) << endl;

    cout << "\n\nFor method 3:" << endl;
    cout << "original-string:" << str1 << " after removing duplicates:" <<  removeDuplicates3(str1) << endl;
    cout << "original-string:" << str2 << " after removing duplicates:" <<  removeDuplicates3(str2) << endl;
    cout << "original-string:" << str3 << " after removing duplicates:" <<  removeDuplicates3(str3) << endl;
    cout << "original-string:" << str4 << " after removing duplicates:" <<  removeDuplicates3(str4) << endl;


    cout << "\n\nFor method 4:" << endl;

    char str5[] = "aaaabbbbcccc";
    char str6[] = "abcde";
    char str7[] = "a";
    char str8[] = "";

    cout << endl;
    cout << "original-string:" << str5 << " after removing duplicates:";
    removeDuplicates4(str5);
    cout << str5 << endl;
    cout << "original-string:" << str6 << " after removing duplicates:";
    removeDuplicates4(str6);
    cout << str6 << endl;
    cout << "original-string:" << str7 << " after removing duplicates:";
    removeDuplicates4(str7);
    cout << str7 << endl;
    cout << "original-string:" << str8 << " after removing duplicates:";
    removeDuplicates4(str8);
    cout << str8 << endl;


   cout << "\n\nFor method 5:" << endl;

    char str9[] = "aaaabbbbccccdddeeefffaaabbb";
    char str10[] = "abcdef";
    char str11[] = "b";
    char str12[] = "";

    cout << endl;
    cout << "original-string:" << str9 << " after removing duplicates:";
    removeDuplicates5(str9);
    cout << str9 << endl;
    cout << "original-string:" << str10 << " after removing duplicates:";
    removeDuplicates5(str10);
    cout << str10 << endl;
    cout << "original-string:" << str11 << " after removing duplicates:";
    removeDuplicates5(str11);
    cout << str11 << endl;
    cout << "original-string:" << str12 << " after removing duplicates:";
    removeDuplicates5(str12);
    cout << str12 << endl;

   cout << "\n\nFor method 6:" << endl;

    char str13[] = "aaaabbbbccccdddeeefffaaabbb";
    char str14[] = "abcdef";
    char str15[] = "b";
    char str16[] = "";

    cout << endl;
    cout << "original-string:" << str13 << " after removing duplicates:";
    removeDuplicates6(str13);
    cout << str13 << endl;
    cout << "original-string:" << str14 << " after removing duplicates:";
    removeDuplicates6(str14);
    cout << str14 << endl;
    cout << "original-string:" << str15 << " after removing duplicates:";
    removeDuplicates6(str15);
    cout << str15 << endl;
    cout << "original-string:" << str16 << " after removing duplicates:";
    removeDuplicates6(str16);
    cout << str16 << endl;




    cout << endl;
    return 0;
}
