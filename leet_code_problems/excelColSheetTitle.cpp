/**
 * Given a positive integer, return its corresponding column title as appear in an Excel sheet.
 *
 * For example:
 *
 *     1 -> A
 *     2 -> B
 *     3 -> C
 *     ...
 *     26 -> Z
 *     27 -> AA
 *     28 -> AB
 *
 * Approach:
 *	   We need to convert the column value to effective a base 26 number, Imagine this is similar
 *	   to converting a decimal to hexadecimal value. However, we need to be cautious of that the
 *	   column numbers are not 0 indexed, they are indexed from 1. So every time our n % 26 is 0,
 *	   we reduce 1 from remaining number.
 *
 */

#include <iostream>
#include <string>
#include <algorithm>

std::string convertToTitle(int n) {
	std::string result("");
	while ( n > 0) {
		int rem = n % 26;
		if ( rem == 0 ) {
			result += 'Z';
			n = (n/26) - 1;
		} else {
			result += char( rem-1 + 'A');
			n = n/26;
		}
	}
	std::reverse(result.begin(), result.end());
	return result;
}

int main()
{
	std::cout << "Enter the column index(1 based):";
	int col;
	std::cin >> col;
	std::cout << "Corresponding excel sheet title for column number "
			  << col << " is :" << convertToTitle(col) << std::endl;
	return 0;
}
