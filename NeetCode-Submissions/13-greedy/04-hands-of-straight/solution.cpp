#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool isNStraightHand(vector<int> &hand, int groupSize)
    {
        if (hand.size() % groupSize != 0)
        {
            return false;
        }

        map<int, int> mp;

        for (int i = 0; i < hand.size(); i++)
        {
            mp[hand[i]]++;
        }

        while (!mp.empty())
        {
            int curr = mp.begin()->first;

            for (int i = 0; i < groupSize; i++)
            {
                if (mp[curr + i])
                {
                    mp[curr + i]--;
                }
                else
                {
                    return false;
                }

                if (mp[curr + i] < 1)
                {
                    mp.erase(curr + i);
                }
            }
        }

        return true;
    }
};

// Time complexity: O(nlogn), where n is the length of the input array hand, since we are iterating through the array once and using a map to store the counts of each element, which takes O(logn) time for insertion and deletion.
// Space complexity: O(n), where n is the length of the input array hand, since