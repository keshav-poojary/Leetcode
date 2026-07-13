#include <bits/stdc++.h>
using namespace std;

class Solution1
{
public:
    bool obtainResult(int num)
    {
        int res = 0;
        int digit = num % 10;
        num = num / 10;
        int acc = digit;
        while (num > 0)
        {
            int digit = num % 10;
            if (acc - digit != 1)
            {
                return false;
            }
            acc = digit;
            num = num / 10;
        }

        return true;
    }
    vector<int> sequentialDigits(int low, int high)
    {
        vector<int> ans;
        for (int i = low; i <= high; i++)
        {
            bool res = obtainResult(i);
            if (res)
            {
                ans.push_back(i);
            }
        }

        return ans;
    }
};



// Time Complexity: O(n * d) where n is the number of integers in the range [low, high] and d is the number of digits in each integer.
// Space Complexity: O(1) since we are using a constant amount of space to store


class Solution2 {
public:
    vector<int> sequentialDigits(int low, int high) {
        vector<int> res;
        string digit = "123456789";

        for (int length = 2; length <= 9; length++) {
            for (int start = 0; start + length <= 9; start++) {
                int number = stoi(digit.substr(start, length));
                if (number >= low && number <= high) {
                    res.push_back(number);
                }
            }
        }

        return res;
    }
};

// Approach : For all possible lengths of sequential digits (from 2 to 9), generate the numbers by taking substrings of the string "123456789". Check if each generated number is within the range [low, high] and add it to the result vector if it is.
// Time Complexity: O(1) since the number of sequential digit numbers is constant and does not depend on the input size.
