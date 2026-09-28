#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool mergeTriplets(vector<vector<int>> &triplets, vector<int> &target)
    {
        bool x = false;
        bool y = false;
        bool z = false;
        for (auto triplet : triplets)
        {
            if (triplet[0] > target[0] || triplet[1] > target[1] ||
                triplet[2] > target[2])
            {
                continue;
            }

            for (int i = 0; i < 3; i++)
            {
                if (triplet[0] == target[0])
                {
                    x = true;
                }

                if (triplet[1] == target[1])
                {
                    y = true;
                }
                if (triplet[2] == target[2])
                {
                    z = true;
                }
            }
        }

        return x && y && z;
    }
};

// Time complexity : 0(n), where n is the length of the input array triplets, since we are iterating through the array once.
// Space complexity : O(1), since we are using only a constant amount of extra space for variables x, y, and z.


// Algorithm: 