#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    void obtainNextSmallestIndex(vector<int> &nextSmallestIndex, int n,
                                 vector<int> &heights)
    {
        stack<int> s;

        for (int i = n - 1; i >= 0; i--)
        {
            while (!s.empty() && heights[s.top()] >= heights[i])
            {
                s.pop();
            }

            if (s.empty())
            {
                nextSmallestIndex.push_back(n);
            }
            else
            {
                nextSmallestIndex.push_back(s.top());
            }

            s.push(i);
        }
        reverse(nextSmallestIndex.begin(), nextSmallestIndex.end());
    }

    void obtainPrevSmallestIndex(vector<int> &prevSmallestIndex, int n,
                                 vector<int> &heights)
    {
        stack<int> s;

        for (int i = 0; i < n; i++)
        {
            while (!s.empty() && heights[s.top()] >= heights[i])
            {
                s.pop();
            }

            if (s.empty())
            {
                prevSmallestIndex.push_back(-1);
            }
            else
            {
                prevSmallestIndex.push_back(s.top());
            }

            s.push(i);
        }
    }

    int largestRectangleArea(vector<int> &heights)
    {
        vector<int> nextSmallestIndex;
        vector<int> prevSmallestIndex;

        obtainNextSmallestIndex(nextSmallestIndex, heights.size(), heights);
        obtainPrevSmallestIndex(prevSmallestIndex, heights.size(), heights);

        int maxi = INT_MIN;
        for (int i = 0; i < heights.size(); i++)
        {
            int val =
                (nextSmallestIndex[i] - prevSmallestIndex[i] - 1) * heights[i];
            maxi = max(maxi, val);
        }

        return maxi;
    }
};

// Time Complexity: O(n) - obtaining next and previous smallest index
// Space Complexity: O(n) - next and previous smallest index vectors and stacks
