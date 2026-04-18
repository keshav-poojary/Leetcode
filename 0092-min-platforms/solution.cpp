#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int minPlatform(vector<int> &arr, vector<int> &dep)
    {
        int count = 0;
        int j = 0;
        sort(arr.begin(), arr.end());
        sort(dep.begin(), dep.end());

        for (int i = 0; i < arr.size(); i++)
        {
            if (arr[i] <= dep[j])
            {
                count++;
            }
            else
            {
                j++;
            }
        }

        return count;
    }
};

// Time Complexity: O(n*log(n)) + O(n*log(n)) + O(n) ~ O(n*log(n))
// Space Complexity: O(1)
