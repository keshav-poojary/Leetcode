#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    vector<int> plusOne(vector<int> &digits)
    {
        for (int i = digits.size() - 1; i >= 0; i--)
        {
            if (digits[i] < 9)
            {
                digits[i]++;
                return digits;
            }
            digits[i] = 0;
        }

        digits.insert(digits.begin(), 1);
        return digits;
    }
};

// Time Complexity: O(n) where n is the number of digits in the input array. In the worst case, we may need to iterate through all the digits to handle the carry-over when adding 1.
// Space Complexity: O(1) if we ignore the space used for the output array.