/*
 * Detect if a number is a happy number. A number is happy number if
 * sequence of operations where number is replaced by sum of square
 * of its digits leads eventually to 1. A number is not a happy number
 * if we are in an infinite loop when above operations are performed.
 * 
 * Input: 49
 * 4^2 + 9^2 = 16 + 81 = 97
 * 9^2 + 7^2 = 81 + 49 = 130
 * 1^2 + 3^2 + 0^2 = 1 + 9 + 0 = 10
 * 1^2 + 0^2 = 1
 * Thus 49 is a happy number.
 * Approach:
 * 
 * We can treat this problem same as finding a cycle in a linked list.
 * Imagine intermediate numbers as node and operation of square and sum
 * as link.
 * If we find the cycle, and the cycle is at 1, number is a happy number.
 * Else, the number is not a happy number.
 */

#include <iostream>

int squareSum(int num)
{
    int squaredSum = 0;
    while (num > 0) {
        squaredSum += (num % 10) * (num % 10);
        num /= 10;
    }
    return squaredSum;
}

bool isHappy(int num)
{
    int slow = num;
    int fast = num;
    
    do {
        slow = squareSum(slow);
        fast = squareSum(squareSum(fast));
    } while (slow != fast);
    return slow == 1;
}

int main()
{
    int num = 45;
    if (isHappy(num)) {
        std::cout << num << " is a happy number." << std::endl;
    } else {
        std::cout << num << " is not a happy number." << std::endl;
    }
    num = 49;
    if (isHappy(num)) {
        std::cout << num << " is a happy number." << std::endl;
    } else {
        std::cout << num << " is not a happy number." << std::endl;
    }
    return 0;
}
