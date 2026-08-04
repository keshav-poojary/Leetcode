#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<vector<int>> insert(vector<vector<int>> &intervals,
                               vector<int> &newInterval)
    {
        vector<pair<int, int>> pairs;
        vector<vector<int>> res;

        for (auto v : intervals)
        {
            pair<int, int> p = make_pair(v[0], v[1]);
            pairs.push_back(p);
        }

        int n = intervals.size();

        int i = 0;

        // left wala correct parts
        while (i < n && pairs[i].second < newInterval[0])
        {
            res.push_back({pairs[i].first, pairs[i].second});
            i++;
        }

        // actual merge
        int mini = newInterval[0];
        int maxi = newInterval[1];
        while (i < n && pairs[i].first <= newInterval[1])
        {
            mini = min(pairs[i].first, mini);
            maxi = max(pairs[i].second, maxi);
            i++;
        }
        res.push_back({mini, maxi});

        while (i < n)
        {
            res.push_back({pairs[i].first, pairs[i].second});
            i++;
        }

        return res;
    }
};

// time complexity: O(n)
// space complexity: O(n)