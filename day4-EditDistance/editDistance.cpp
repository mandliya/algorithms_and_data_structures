/*
	Dynamic Programming approach to solve minimum edit cost required to change string s1 to s2
*/

#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;

//Delete cost
const int D=1;
//Insert cost
const int I=1;
//Replace cost
const int R=1;

int minimum(int a, int b, int c){
	return min(a, min(b,c));
}

int editDistance(char *X, char *Y){
	
	//cost of alignment
	int cost =0;

	int m = strlen(X)+1;
	int n = strlen(Y)+1;

	
	//DP array
	int **T = new int*[m];
	for(int i = 0; i < m; ++i){
		T[i] = new int[n];
	}
	
	//initializing DP array with cost -1 
	for(int i =0; i < m; ++i){
		for(int j = 0; j < n; ++i){
			T[i][j] = -1;
		}
	}
	
	//setting up base cases; 
	//T[i][0] = 0
	for(int i = 0;i < m; ++i){
		T[i][0] = i;
	}

	//T[0][j] = 0
	for(int j = 0; j < n; ++j){
		T[0][j] = j;
	}

	//Let us fill up the DP table in top-down fashion

	int left, top, corner;
	for( int i = 1; i < m; ++i){
		for(int j = 1; j < n; ++j){

			//T[i][j-1] case of delete(check readme)	
			left = T[i][j-1];
			left += D;	
			
			//T[i-1][j] case of insert(check readme)
			top = T[i-1][j];
			top += I;

			//T[i-1][j-1]
			corner = T[i-1][j-1];
			if(X[i-1] != Y[j-1]){
				corner += R;
			}
			
			T[i][j] = minimum(left, top, corner);
		}
	}

	cost = T[m][n];
	for( int i = 0; i < m; ++i){
		delete[] T[i];
	}
	
	delete T;
	return cost;
}


int main()
{
   cout<<"Enter the source String:";
   char X[50];
   cin>>X;

   cout<<"Enter destination string:";
   char Y[50];
   cin>>Y;

 
    cout<< "Minimum edits required to convert "<<X<<" into "<<Y<<" is:"<<editDistance(X, Y)<<endl;
 
    return 0;
}
