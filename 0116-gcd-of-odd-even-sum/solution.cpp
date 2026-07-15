#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int gcd(int sumOdd, int sumEven)
    {
        if (sumEven == 0)
        {
            return sumOdd;
        }
        return gcd(sumEven, sumOdd % sumEven);
    }

    int gcdOfOddEvenSums(int n)
    {
        int sumOdd = 0;
        int sumEven = 0;

        int i = 1;
        while (i <= 2 * n)
        {
            if (i % 2 == 0)
            {
                sumEven = sumEven + i;
            }
            else
            {
                sumOdd = sumOdd + i;
            }
            i++;
        }

        return gcd(sumOdd, sumEven);
    }
};

// Time Complexity: O(n) where n is the input integer. We iterate through the numbers from 1 to 2n to calculate the sums of odd and even numbers, and then we compute the GCD of the two sums.
// Space Complexity: O(1) since we are using a constant amount of space to store the sums and the GCD result.