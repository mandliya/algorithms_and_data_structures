// https : // practice.geeksforgeeks.org/problems/celsius-to-fahrenheit-conversion5212/1#

class Solution
{
public:
    double celciusToFahrenheit(int C)
    {

        double ans = (C * 9.0) / 5.0 + 32;

        return ans;
    }
};