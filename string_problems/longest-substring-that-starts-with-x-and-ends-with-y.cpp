#include <bits/stdc++.h>  
using namespace std;  

int longestSubstring(string str, char X, char Y)  
{  
    // Length of string  
    int N = str.length();  
    int start = 0;  
    int end = N - 1;  
    int xPos = 0;  
    int yPos = 0;  
  
    // Find the length of the string  
    // starting with X from the beginning  
    while (true) {  
  
        if (str[start] == X) {  
            xPos = start;  
            break;  
        }  
        start++;  
    }  
  
    // Find the length of the string  
    // ending with Y from the end  
    while (true) {  
  
        if (str[end] == Y) {  
            yPos = end;  
            break;  
        }  
        end--;  
    }  
  
    // Longest substring  
    int length = (yPos - xPos) + 1;  
  
    // Print the length  
    cout << length;  
}  
    
int main()  
{  
    string str = "HASFFDJGHOGAKZZFEGABCDF";  
  
    // Starting and Ending characters  
    char X = 'A', Y = 'Z';
  
    // Function Call  
    longestSubstring(str, X, Y);  
    return 0;  
}  
