#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    static bool comp(pair<int, int> first, pair<int, int> second)
    {
        return second.second > first.second;
    }

    int eraseOverlapIntervals(vector<vector<int>> &intervals)
    {
        vector<pair<int, int>> p;

        for (int i = 0; i < intervals.size(); i++)
        {
            pair<int, int> value = make_pair(intervals[i][0], intervals[i][1]);
            p.push_back(value);
        }

        sort(p.begin(), p.end(), comp);

        int count = 0;
        int last = p[0].second;
        for (int i = 1; i < p.size(); i++)
        {
            if (p[i].first < last)
            {
                count++;
            }
            else
            {
                last = p[i].second;
            }
        }

        return count;
    }
};