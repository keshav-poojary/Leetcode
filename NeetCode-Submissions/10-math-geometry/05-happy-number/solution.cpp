#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int obtainReverse(int n)
    {
        int sum = 0;
        while (n > 0)
        {
            int digit = n % 10;
            sum = sum + (digit * digit);
            n = n / 10;
        }
        return sum;
    }
    bool isHappy(int n)
    {
        while (n != 1 && n != 4)
        {
            n = obtainReverse(n);
        }

        return n == 1;
    }
};

// Time Complexity: O(log n) where n is the input number. This is because we are repeatedly calculating the sum of squares of digits of n, which takes O(log n) time.
// Space Complexity: O(1) as we are using a constant amount of space for variables

//Every happy number will eventually reach 1, while every unhappy number will eventually reach 4. Therefore, we can use this property to determine if a number is happy or not. If we reach 1, the number is happy; if we reach 4, the number is unhappy.