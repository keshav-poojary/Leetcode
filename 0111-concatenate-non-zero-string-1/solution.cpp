#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    long long sumAndMultiply(int n)
    {
        long long x = 0;
        int counter = 1;
        while (n > 0)
        {
            int digit = n % 10;
            if (digit != 0)
            {
                x = x + (counter * digit);
                counter = counter * 10;
            }
            n = n / 10;
        }

        long long sum = 0;
        long long y = x;

        while (x > 0)
        {
            int digit = x % 10;
            sum = sum + digit;
            x = x / 10;
        }

        return y * sum;
    }
};