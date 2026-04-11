#include <vector>
#include <stack>
#include <algorithm>
using namespace std;

class Solution
{
public:
    vector<int> createPreviousSmallerElements(vector<int> &heights)
    {
        vector<int> ans;
        stack<int> s;

        for (int i = 0; i < heights.size(); i++)
        {
            while (!s.empty() && heights[s.top()] >= heights[i])
            {
                s.pop();
            }

            if (s.empty())
            {
                ans.push_back(-1);
            }
            else
            {
                ans.push_back(s.top());
            }
            s.push(i);
        }

        return ans;
    }

    vector<int> createNextSmallerElements(vector<int> &heights)
    {
        vector<int> ans;
        stack<int> s;

        for (int i = heights.size() - 1; i >= 0; i--)
        {
            while (!s.empty() && heights[s.top()] >= heights[i])
            {
                s.pop();
            }

            if (s.empty())
            {
                ans.push_back(-1);
            }
            else
            {
                ans.push_back(s.top());
            }
            s.push(i);
        }

        reverse(ans.begin(), ans.end());

        return ans;
    }

    int largestRectangleArea(vector<int> &heights)
    {
        int size = heights.size();
        vector<int> ps(size);
        vector<int> ns(size);
        ns = createNextSmallerElements(heights);
        ps = createPreviousSmallerElements(heights);
        for (int i = 0; i < ns.size(); i++)
        {
            if (ns[i] == -1)
            {
                ns[i] = size;
            }
        }

        int maxi = INT_MIN;
        int curr = 0;

        for (int i = 0; i < heights.size(); i++)
        {
            curr = (ns[i] - ps[i] - 1) * heights[i];
            maxi = max(maxi, curr);
        }

        return maxi;
    }
};

// Time Complexity: O(n)
// Space Complexity: O(n) for the stacks and the previous and next smaller element arrays