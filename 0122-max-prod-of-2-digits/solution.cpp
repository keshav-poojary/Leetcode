#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> buildValues(int n)
    {
        vector<int> res;
        while (n > 0)
        {
            int digit = n % 10;
            res.push_back(digit);
            n = n / 10;
        }
        return res;
    }
    int maxProduct(int n)
    {
        vector<int> ans;
        ans = buildValues(n);
        sort(ans.begin(), ans.end());
        int size = ans.size();

        int res = ans[size - 1] * ans[size - 2];
        return res;
    }
};

// Time complexity : o(nlogn) -> sort
// space complexiuty : o(n) -> vector to store digits