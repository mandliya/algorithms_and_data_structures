//date: 3 jun 2019
//reverse a string using stack
#include<iostream>
#include<stack>
#include<string.h>

using namespace std;

void reverse(char *c, int n){
    stack<char> s;
    //push
    for(int i = 0;i<n;i++){
        s.push(c[i]);
    }
    //pop
    for(int i=0;i<n;i++){
        c[i] = s.top();
        s.pop();
    }        
}
int main(){
    char c[100];
    cin>>c;
    reverse(c,strlen(c));
    cout<<c;

    return 0;
}