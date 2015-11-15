/**
 * In Quantumland, there are n cities numbered from 1 to n. Here, ci denotes the ith city.
 * There are n−1 roads in Quantumland. Here, ci and ci+1 have a bidirectional road between them for each i<n.
 * There is a rumor that Flatland is going to attack Quantumland, and the queen wants to keep her land safe.
 * The road between ci and ci+1 is safe if there is a guard in ci or ci+1.
 * The queen has already placed a few guards in some of the cities,
 * but she is not sure if they are enough to keep the roads safe.
 * She wants to know the minimum number of new guards she needs to hire.
 *
 * Input format:
 * The first line will contain an integer n.
 * In the next line, there will be n integers b1,b2...bn.
 *
 * If bi=1, that means there is a guard in city ci.
 * If bi=0, that means there are no guards in city ci.
 *
 * Example input
 * 5
 * 1 1 0 1 0
 * 5
 * 0 0 1 0 0
 *
 * Output:
 * 0
 * 2
 *
 */

#include <vector>
#include <iostream>



int min_guards_required(std::vector<int> & cities ) {
	int guardCount = 0;
	int unsafeRoads = 0;
	int n = cities.size();
	if ( n == 1 ) {
		std::cout << guardCount << std::endl;
		return 0;
	}
	int i = 0;
	while ( i < n - 1 ) {
		unsafeRoads = 0;
		if (cities[i] == 0 && cities[i+1] == 0) {
			while(i < n-1 && cities[i] == 0 && cities[i+1] == 0) {
				++unsafeRoads;
				++i;
			}
			if ( unsafeRoads <= 2 ) {
				guardCount += 1;
			} else {
				if ( unsafeRoads % 2 ) {
					guardCount += (unsafeRoads/2) + 1;
				} else {
					guardCount += unsafeRoads/2;
				}
			}
		}
		++i;
	}
	return guardCount;
}


int main() {
	int n;
	std::cin >> n;
	std::vector<int> cities(n);
	for(int i = 0; i < n; i++){
		std::cin >> cities[i];
	}
	std::cout << min_guards_required(cities) << std::endl;
    return 0;
}

