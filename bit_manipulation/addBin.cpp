/*
 * Add two binary numbers represented as string.
 *
 */

#include <iostream>

std::string addBinary(std::string & string1, std::string & string2){
	int temp1=0, temp2=0;
	int i=0;
	std::string temp_string;
    
	for(i; i<string1.size(); ++i){
		temp1 |= ((string1[i] - '0') << (string1.size() - i - 1));
	}
	for(i=0; i<string2.size(); ++i){
		temp2 |= ((string2[i] - '0') << (string2.size() - i - 1));
	}
	temp1 += temp2;
	int count = string1.size();
	for(i=0; i<count+1; ++i){
		if(temp1 & (1<<count-i) && temp1 < (1<<count-i)){
			break;
		}
		else if(temp1 & (1<<count-i)){
			temp_string.append("1");	
		}
		else{
			temp_string.append("0");
		}
	} 
	return temp_string;
}

int main()
{
    std::string str1("1010");
    std::string str2("1011");
    std::cout << "Addition of " << str1 << " and " << str2 << " is :" << addBinary(str1, str2) << std::endl;
    return 0;

}
