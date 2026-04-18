#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    static bool comp(pair<int, int> first, pair<int, int> second)
    {
        return second.second > first.second;
    }

    int activitySelection(vector<int> &start, vector<int> &finish)
    {
        // code here
        vector<pair<int, int>> p;

        for (int i = 0; i < start.size(); i++)
        {
            pair<int, int> value = make_pair(start[i], finish[i]);
            p.push_back(value);
        }

        sort(p.begin(), p.end(), comp);

        int ans = 1;
        int last = p[0].second;

        for (int i = 1; i < p.size(); i++)
        {
            if (p[i].first > last)
            {
                ans++;
                last = p[i].second;
            }
        }

        return ans;
    }
};

// Time Complexity: O(n*log(n)) + O(n) ~ O(n*log(n))
// Space Complexity: O(n)