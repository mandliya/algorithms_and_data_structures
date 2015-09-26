/**
 *  Implement next permutation algorithm. i.e
 *  Given a word w, rearrange the letters of w to construct another word s in such a way that
 *  s is lexicographically greater than w.
 *  In case of multiple possible answers, find the lexicographically smallest one.
 *  Example:
 *  ab --> ba
 *  bb --> bb
 *  hefg --> hegf
 *  dhck --> dhkc
 *  dkhc --> hcdk
 */

#include <iostream>

std::string
next_permutation( std::string str)
{
  int len = str.length();
  int i = len -1;
  // We will iterate string from end, and once we have encountered a pair of letters
  // such that str[i] < str[i-1] , i-1 would become our pivot
  while( i > 0 && str[i] <= str[i-1] ) {
    --i;
  }
  if ( i == 0 ) {
    return str;
  }
  //our pivot right now would be str[i-1]
  int j = len - 1;
  while( j >= i && str[j] <= str[i-1] ) {
    --j;
  }
  std::swap(str[i-1], str[j]);
  j = len - 1;
  //reverse the suffix
  while( i < j ) {
    std::swap(str[i], str[j]);
    --j;
    ++i;
  }
  return str;
}

int main()
{
  std::string str, str_next;
  std::cout << "Enter a string : ";
  std::cin >> str;
  str_next = next_permutation(str);
  std::cout << "Next permutation of " << str << " is "
            << str_next << std::endl;
  return 0;
}
