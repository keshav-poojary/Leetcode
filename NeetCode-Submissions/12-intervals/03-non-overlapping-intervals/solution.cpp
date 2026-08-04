#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
// sort based on the second element of the pair
    bool static comp(pair<int, int> a, pair<int, int> b)
    {
        return a.second < b.second;
    }
    int eraseOverlapIntervals(vector<vector<int>> &intervals)
    {
        vector<pair<int, int>> pairs;
        vector<vector<int>> res;

        for (auto v : intervals)
        {
            pair<int, int> p = make_pair(v[0], v[1]);
            pairs.push_back(p);
        }

        sort(pairs.begin(), pairs.end(), comp);

        int n = intervals.size();
        int second = pairs[0].second;
        int count = 0;
        int i = 1;

        while (i < n)
        {
            if (pairs[i].first < second)
            {
                count++;
            }
            else
            {
                second = pairs[i].second;
            }
            i++;
        }

        return count;
    }
};