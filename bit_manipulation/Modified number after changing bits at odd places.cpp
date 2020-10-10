/*Given a number say (N). Task is to change all the bits at odd places in binary form of N and create a new modified number say(M).print M.

INPUT = 8

Binary representation of 8 = 1000 

Binary representation of new number = 0010(after changing bits at odd places/position starting from 0 ) 

OUTPUT = 2*/
#include <iostream>
#include<cmath>//for power function
using namespace std;
int REPLACE_ODD(string h){
  for(int i=0;i<h.length();i++){
      if(i%2!=0){
          if(h[i]=='1'){h[i]='0';}
          else{h[i]='1';}
      }
  }
//Now string h is the binary representation of modified number 
  int decimal_form = 0;
  for(int j = 0 ; j < h.length() ; j++ ){
    if(h[j] == '1'){decimal_form += pow( 2 , (h.length()-j-1) );}
  }
  return decimal_form;//Modified number
}
int main() {
    int n = 10;//INPUT
    string binary_form="";
    while( n !=0 ){
      binary_form += to_string( n%2 );
      n = n/2 ;
    }
//Now binary representation of number n stored in string binary_form is in reverse form
    cout<< REPLACE_ODD( binary_form ) <<endl;
    return 0;
}

