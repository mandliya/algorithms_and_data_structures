/*Given a string say(K) , consist of Characters(N,O,A) representing NOT , OR , AND logic gate and numbers (1,0).
The task is to iterate through the string character by character and find the last bit left after iteration as 
explained in the example bellow:-
(INITIAL BIT IS ASSUMED TO BE 1)

--------------------------------------------------------------------------
EXAMPLE 1:-

  INPUT-

  K= NA0NO0A1

  OUTPUT:-

  1

  Explanation:- 

  K =NA0NO0A1 (string)

  initial bit is 1 (given).

  first character N :- bit = not of 1 = 0.

  now bit is 0

  second character A and digit is 0 :- bit = and of 0 and bit(0) = 0.

  now bit is 0

  Fourth character N :- bit = not of bit(0) = 1

  now bit = 1

  Fifth character O and digit is 0 :- bit = or of 0 and bit(1) = 1

  now bit = 1

  Seventh character A and digit is 1 :- bit = and of 1 and bit(1) = 1

  now bit = 1(output)
--------------------------------------------------------------------
  EXAMPLE 2:-

  INPUT-

  K= NNNA1

  OUTPUT:-

  1

  Explanation:-

  K =NNNA1 (string)

  initial bit is 1 (given).

  first character N :- bit = not of 1 = 0.

  now bit is 0

  second character N :- bit = not of bit(0) = 1.

  now bit is 1

  third character N :- bit = not of bit(0) = 0

  now bit = 0

  fourth character A and digit is 1 :- bit = and of 1 and bit(0) = 0

  now bit = 0(output)*/
#include <iostream>
using namespace std;
int BIT_OUTPUT(string h) {
    //Initial bit.
    int bit=1;
    
    //Iterating through each character.
    for(int i=0;i<h.length();i++){
        
        if(h[i]=='N'){bit=!bit;}
        //NOT of bit.
        
        else if(h[i]=='A'){bit=bit&(h[i+1]-48);}
        //bitwise AND of previous bit with next digit
        
        else if(h[i]=='O'){bit=bit|(h[i+1]-48);}
        //bitwise OR of previous bit with next digit
        
    }
    return bit;

}
int main() {
    string h ="NNNA1";
    //String of gates
    cout<<BIT_OUTPUT(h)<<endl;//return final bit.
	return 0;
}
