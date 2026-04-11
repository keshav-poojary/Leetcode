#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> countDistinct(vector<int> &arr, int k)
    {
        // code here
        vector<int> ans;

        unordered_map<int, int> mp;

        for (int i = 0; i < k; i++)
        {
            mp[arr[i]]++;
        }

        ans.push_back(mp.size());

        for (int i = k; i < arr.size(); i++)
        {
            int index = i - k;
            int value = arr[index];

            if (mp[value] == 1)
            {
                mp.erase(value);
            }
            else
            {
                mp[value] = mp[value] - 1;
            }

            mp[arr[i]]++;
            ans.push_back(mp.size());
        }

        return ans;
    }
};

// Time Complexity: O(n)
// Space Complexity: O(k)
// The idea is to use a hash map to store the frequency of elements in the current window