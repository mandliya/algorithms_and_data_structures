/**
 * Given two words word1 and word2, find the minimum number of steps required to convert word1 to word2. (each operation is counted as 1 step.)
 *
 * You have the following 3 operations permitted on a word:
 *
 * a) Insert a character
 * b) Delete a character
 * c) Replace a character
 *
 */

#include <iostream>
#include <string>

using std::string;

int min( int a, int b, int c ) {
	int minab = ( a  < b ) ? a : b;
	return ( minab < c ) ? minab:c;
}

int minEditDistance(string word1, string word2) {
	int len1 = word1.size();
	int len2 = word2.size();
	int minCost;
	int ** table = new int*[len1+1];
	for ( int i = 0;i <= len1; ++i ) {
		table[i] = new int[len2+1];
	}

	for (int i = 0; i <= len1; ++i) {
		for (int j = 0; j <= len2; ++j ) {
			if ( i == 0 ) {
				table[i][j] = j;
			}
			else if ( j == 0 ) {
				table[i][j] = i;
			} else if ( word1[i-1] == word2[j-1]) {
				table[i][j] = table[i-1][j-1];
			} else {
				table[i][j] = 1+ min(table[i-1][j-1], table[i][j-1], table[i-1][j]);
			}
		}
	}
	minCost = table[len1][len2];
	for ( int i = 0; i <= len1; ++i ) {
		delete table[i];
	}
	delete[] table;
	return minCost;
}


int main() {
	std::string word1, word2;
	std::cout << "Enter word 1 : " ;
	std::cin >> word1;
	std::cout << "Enter word 2 : " ;
	std::cin >> word2;
	std::cout << "Min edit distance : " << minEditDistance(word1, word2) << std::endl;
	return 0;
}
