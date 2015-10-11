#include <iostream>
#include <string>
#include <vector>


/**
 * Function to fill in zvalues vector of ztext
 */
std::vector<size_t> fillZvalues(const std::string & ztext) {
	size_t n = ztext.length();
	std::vector<size_t> zvals(n, 0);
	size_t L = 0, R = 0; 								// s[L..R] represent the prefix string.
	for (size_t i = 1; i < n; ++i) {
		if ( i > R ) {
			L = R = i;
			while( R < n && ztext[R-L] == ztext[R] ) {
				++R;
			}
			zvals[i] = R-L;
			--R;
		} else {
			size_t K = i - L;
			if( zvals[K] < R-i+1 ) {
				zvals[i] = zvals[K];
			} else {
				L = R = i;
				while( R < n && ztext[R-L] == ztext[R] ) {
					++R;
				}
				zvals[i] = R-L;
				--R;
			}
		}
	}
	return zvals;
}

/**
 * This function returns index of text where pattern matches using z algorithm
 */
std::vector<size_t> search( const std::string & text, const std::string & pattern ) {
	std::string ztext = pattern + '$' + text;
	std::vector<size_t> zvalues = fillZvalues(ztext);
	std::vector<size_t> indices;
	for ( size_t i = 1; i < zvalues.size(); ++i ) {
		if (zvalues[i] == pattern.length()) {
			indices.push_back(i - pattern.length() -1 );
		}
	}
	return indices;
}

int main()
{
	std::string text, pattern;
	std::cout << "String searching using Z algorithm:\n";
	std::cout << "Enter text:";
	std::getline(std::cin, text);
	std::cout << "Pattern :";
	std::getline(std::cin, pattern);
	std::vector<size_t> indices = search(text, pattern);
	for (auto i : indices ) {
		std::cout << pattern << " occurs in given text starting at index " << i << std::endl;
	}
	return 0;
}
