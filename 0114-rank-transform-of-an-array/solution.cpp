#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> arrayRankTransform(vector<int> &arr)
    {
        map<int, int> mp;
        int rank = 1;

        vector<int> temp = arr;
        sort(temp.begin(), temp.end());

        for (auto ele : temp)
        {
            if (mp.find(ele) == mp.end())
            {
                mp[ele] = rank++;
            }
        }

        for (int i = 0; i < arr.size(); i++)
        {
            arr[i] = mp[arr[i]];
        }

        return arr;
    }
};

// Time Complexity: O(nlogn) + O(n) + O(n) ~ O(nlogn)
// Space Complexity: O(n) + O(n) ~ O(n)
