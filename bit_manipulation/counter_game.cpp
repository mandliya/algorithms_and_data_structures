
/*
Louise and Richard play a game. They have a counter set to N. Louise gets the first turn and the turns alternate thereafter. In the game, they perform the following operations.

If N is not a power of 2, reduce the counter by the largest power of 2 less than N.
If N is a power of 2, reduce the counter by half of N.
The resultant value is the new N which is again used for subsequent operations.
The game ends when the counter reduces to 1, i.e., N == 1, and the last person to make a valid move wins.

Given N, your task is to find the winner of the game.
If they set counter to 1, Richard wins, because its Louise' turn and she cannot make a move.

Input Format 
The first line contains an integer T, the number of testcases. 
T lines follow. Each line contains N, the initial number set in the counter.

*/



#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

bool isPowerOf2(unsigned long long int x) {
    return ( x && ((x &(x-1)) == 0));
}

unsigned long long int lowerPowerof2( unsigned long long int x) {
     if (x == 0) {
        return 0;
    }
    x--;
    x |= (x >> 1);
    x |= (x >> 2);
    x |= (x >> 4);
    x |= (x >> 8);
    x |= (x >> 16);
    x |= (x >> 32);
    return x - (x >> 1);
}

std::string winner( bool win ) {
    if (win) {
        return std::string("Louise");
    } else {
        return std::string("Richard");
    }
}

int main() {
    
    int T;
    unsigned long long int N;
    cin >> T;
    
    while(T) {
        cin >> N;
        if (N == 1) {
            std::cout << "Richard\n";
            continue;
        }
        bool win = false;
        while(N > 1) {
            if (isPowerOf2(N)) {
                N = N/2;
            } else {
                N = N - lowerPowerof2(N);
            }
            win = !win;
        }
        std::cout << winner(win) << std::endl;
        --T;
    }
    
    return 0;
}


