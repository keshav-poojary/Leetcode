#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool static comp(pair<int, int> a, pair<int, int> b)
    {
        return a.first < b.first;
    }
    bool canAttend(vector<vector<int>> &arr)
    {
        // Code Here
        vector<pair<int, int>> p;
        for (auto ele : arr)
        {
            pair<int, int> temp_pair = make_pair(ele[0], ele[1]);
            p.push_back(temp_pair);
        }

        sort(p.begin(), p.end(), comp);

        int second = p[0].second;

        for (int i = 1; i < p.size(); i++)
        {
            if (p[i].first < second)
            {
                return false;
            }
            else
            {
                second = p[i].second;
            }
        }

        return true;
    }
};
