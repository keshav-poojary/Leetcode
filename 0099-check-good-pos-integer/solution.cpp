#include <iostream>
using namespace std;

class Solution
{
public:
    int findDigitSum(int n)
    {
        int sum = 0;
        while (n > 0)
        {
            int rem = n % 10;
            sum = sum + rem;
            n = n / 10;
        }
        return sum;
    }

    int findSquareSum(int n)
    {
        int sum = 0;
        while (n > 0)
        {
            int rem = n % 10;
            sum = sum + (rem * rem);
            n = n / 10;
        }
        return sum;
    }

    bool checkGoodInteger(int n)
    {
        int digitSum = findDigitSum(n);
        int squareSum = findSquareSum(n);
        return squareSum - digitSum >= 50 ? true : false;
    }
};

// Time Complexity: O(log n) where n is the input integer. This is because we are iterating through the digits of the number.
// Space Complexity: O(1) because we are using a constant amount of space to store