/**
 *  Given an infix expression, convert it to postfix. Consider usual operator precedence.
 *  Consider only following operands in your arsenal.
 *  +, -, * , /, ^(power)
 *  Operands are only alphabets --> 'a '-->'z' and 'A'-->'Z'
 *  Another assumption is operand is a single char.
 */

#include <iostream>
#include <stack.h>
#include <string>

// all utility and main functions declared first
/**
 * isOperator- Determines if input char is operator
 * @param  c - char
 * @return   - true or false
 */
bool isOperator( char c );

/**
 * isOperand Determines if input char is operand
 * @param  c - char
 * @return   true or false.
 */
bool isOperand( char c );


/**
 * getOperatorWeight returns an integer weight of the operator
 * @param  c  - An operator
 * @return   Weight of operator , larger is more precedence
 */
int getOperatorWeight(char c);


/**
 * isRightAssociative -Determines if operator is right associative.
 * @param  c operator
 * @return   returns true if operator is right associative
 *
 * Associativity only comes to picture when both operators have same weight
 * Example ^ is right associative ( ^ represents power of)
 * 5 ^ 4 ^ 3 ^ 2  = 5 ^ ( 4 ^ ( 3 ^ 2 ) )
 * where as  7 − 4 + 2 (7 − 4) + 2 = 5 or 7 − (4 + 2) = 1
 */
bool isRightAssociative(char c);

/**
 * [hasHigherPrecedence] compare op1 and op2 based on precedence
 * @param  op1 operaror 1
 * @param  op2 operator 2
 * @return     return true if precedence(op1) > precedence(op2), else false
 */
bool hasHigherPrecedence(char op1, char op2);

/**
 * [infixToPostfix - converts infix expr to postfix expr
 * @param  expression - infix expre
 * @return            postfix expr
 */
std::string infixToPostfix( std::string expression );


//check if c is an operator
bool isOperator( char c )
{
  if ( c == '+' || c == '-' || c == '*' || c == '/' || c == '^') {
    return true;
  }
  return false;
}

//check if c is a valid operand defined in comments.
bool isOperand( char c )
{
  if ( c >= 'a' && c <= 'z' ) return true;
  if ( c >= 'A' && c <= 'Z' ) return true;
  return false;
}

//returns precedence weight of the char c.
// more weight higher precedence.
int getOperatorWeight( char c )
{
  int weight;
  switch(c) {
    case '+':
    case '-':
      weight = 1;
      break;
    case '*':
    case '/':
      weight = 2;
      break;
    case '^':
      weight = 3;
      break;
    default:
      weight = -1;
  }
  return weight;
}


// is operator right associative?
bool isRightAssociative( char op )
{
  if ( op == '^') return true;
  return false;
}

bool hasHigherPrecedence( char op1, char op2 )
{
  // get weight of the operators
  int w1 = getOperatorWeight(op1);
  int w2 = getOperatorWeight(op2);

  // If both operators weigh same, return true if operators are
  // left associative, return false if right associative.
  if ( w1 == w2 ) {
    if ( isRightAssociative(op1) ) {
      return false;
    }
    return true;
  }
  return w1 > w2 ? true : false;
}

// final function to convert infix to postix operator.

std::string infixToPostFix(std::string expr)
{
  bool errorDetected = false;
  algo::Stack<char> operatorStack;
  std::string postFixExpr = "";

  //scanning input infix expr left to right char by char
  for ( char c : expr ) {

    // char is delimiter, continue
    if ( c == ',' || c == ' ') {
      continue;
    }

    //if character is an operand
    else if ( isOperand(c) ) {
      postFixExpr += c;
    }

    //if character is operator
    else if ( isOperator(c) ) {
      //if stack is not empty pop the stack back and compare precedence.
      //if higher precedence perform operation.
      while ( !operatorStack.empty() &&  operatorStack.top() != '(' &&
              hasHigherPrecedence(operatorStack.top(), c) ) {
          postFixExpr += operatorStack.top();
          operatorStack.pop();
      }
      operatorStack.push(c);
    }

    else if( c == '(' ) {
      operatorStack.push(c);
    }

    else if( c == ')' ) {
      while( !operatorStack.empty() && operatorStack.top() != '(' ) {
        postFixExpr += operatorStack.top();
        operatorStack.pop();
      }
      operatorStack.pop();
    }

    else {
      std::cout << " ERROR An invalid operator/operand detected\n";
      errorDetected = true;
      break;
    }
  }
  if (errorDetected) {
    return "INVALID EXPR!";
  }

  while( !operatorStack.empty() ) {
    postFixExpr += operatorStack.top();
    operatorStack.pop();
  }
  return postFixExpr;
}


int main()
{
  std::string expr;
  std::cout << "Provide an expression such that :"
            << "1. Expression shoule be parenthesis valid.\n"
            << "2. Operators should contain +, -, /, *, ^\n"
            << "3. Operands should contain A-Z or a-z \n"
            << "Your expression is :";
  std::getline(std::cin, expr);
  std::cout << "Corresponding postfix expression of the express - "
            << expr
            << " is :" << infixToPostFix(expr) << std::endl;
  return 0;
}
