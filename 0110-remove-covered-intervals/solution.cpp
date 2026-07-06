#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    static bool comp(pair<int, int> a, pair<int, int> b)
    {
        if (a.first == b.first)
        {
            return a.second > b.second; // if start is same, end which is larger pick that
        }
        return a.first < b.first; // if start is not same, pick the smaller start
    }

    int removeCoveredIntervals(vector<vector<int>> &intervals)
    {
        vector<pair<int, int>> pairs;

        for (auto interval : intervals)
        {
            int first = interval[0];
            int second = interval[1];
            pair<int, int> p = make_pair(first, second);
            pairs.push_back(p);
        }

        sort(pairs.begin(), pairs.end(), comp);

        int maxi = pairs[0].second;
        int count = 1;

        for (int i = 1; i < pairs.size(); i++)
        {
            if (pairs[i].second > maxi)
            {
                maxi = pairs[i].second;
                count++;
            }
        }

        return count;
    }
};