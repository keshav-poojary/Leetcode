#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int obtainAns(int n)
    {
        int res = 0;
        while (n != 0)
        {
            if (n & 1)
            {
                res += 1;
            }
            n = n >> 1;
        }
        return res;
    }
    vector<int> countBits(int n)
    {
        vector<int> ans;

        for (int i = 0; i <= n; i++)
        {
            int count = obtainAns(i);
            ans.push_back(count);
        }

        return ans;
    }
};