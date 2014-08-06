/*	day 1 - August 8 2014
	Problem : Reverse words in a sentence.
	example Input : The food tastes awesome
	example Output: awesome tastes food The

	Algorithm:
		Reverse the individual words, the sentence becomes    - 'ehT doof setsat emosewa'
		Reverse the entire string now, the sentence becomes    - 'awesome tastes food The'

*/

#include<iostream>
#include<cstring>

/*
	utility function     :reverse
	parameters   : start char and end char 
	change/output:reverses the input string starting at 'start' char and ending and 'end' char
*/

void reverse(char *start, char *end){
	char temp;
	while(start < end){
		temp = *start;
		*start++ = *end;
		*end--  = temp;
	}
}

/*
	main function: 	reverseWords
	parameter : Input string 
	purpose : reverses each individual word separated by the space, and then reverses the entire string to give the desired output.

*/

void reverseWords(char *input){

	//step 1 reverse individual words 
	char *temp = input;
	char *wordBegin = NULL;
	while(*temp){
		if( (wordBegin == NULL) && (*temp != ' ')){
			wordBegin = temp;
		} 
		if(wordBegin && (*(temp+1)==' ' || *(temp+1)=='\0')){
			reverse(wordBegin, temp);
			wordBegin  = NULL;
		}
		temp++;
	}
	
	//Step 2 reverse the entire string now
	reverse(input, temp-1); 
}


int main(){
	char inputString[] = "The food tastes awesome";
	reverseWords(inputString);
	std::cout<<"The reversed sentence:"<<inputString<<std::endl;
	return 0;
}
