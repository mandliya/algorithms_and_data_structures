//PARENTHESIS CHECKER
//This program will work for all possible values of expressions

#include <iostream>
using namespace std;

// Defining the maximum size of the stack to be 10
#define MAX 10

// Defining a class to store the member variables
// and member functions required
class Stack {
  int stk[MAX];

public:
  int top;
  Stack(): top(-1) {}
  void push(char );
  char pop();
  void display();
};

void Stack :: push(char value) {
  // When the size of stack has reached maximum,
  // we cannot insert any element
  if(top == MAX-1) {
    cout<<"The Stack is full !\n";
  }
  else {
    // Incrementing top
    top++;

    // Store the value in the stack at top position
    stk[top] = value;
  }
}


char Stack :: pop() {
  // When the size of stack is -1, the stack is empty
  if(top == -1) {
    cout<<"The Stack is empty !\n";
    return -1;
  }
  else {
    // Store the top value
    char value = stk[top];

    // Decrement top
    top --;

    return value;
  }
}


int main() {
  Stack s;
  string exp;
  char temp;
  int flag = 1;

  cout<<"Enter the expression: ";
  getline(cin, exp);

  for(int i=0; i < exp.length(); i++) {
    if(exp[i] == '(' || exp[i] == '{' || exp[i] == '[') {
      s.push(exp[i]);
    }
    if(exp[i] == ')' || exp[i] == '}' || exp[i] == ']') {
      if(s.top == -1) {
        flag = 0;
      }
      else {                                  
        temp = s.pop();
        
        //making flag=0 for every possible invalid popped elemnt
        if((exp[i] == ')') && (temp != '(')) 
          flag = 0;
        
        if((exp[i] == '}') && (temp != '{'))
          flag = 0;
        
        if((exp[i] == ']') && (temp != '['))
          flag = 0;
      }
    }
  }

  if(s.top >= 0) {    //i.e some element is still left in the stack
    flag = 0;
  }

  if(flag == 1) {
    cout<<"The expression is valid.\n";
  }
  else {
    cout<<"The expression is not valid.\n";
  }
}
