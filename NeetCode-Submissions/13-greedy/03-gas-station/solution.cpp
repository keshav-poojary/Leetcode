#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int canCompleteCircuit(vector<int> &gas, vector<int> &cost)
    {
        int totalGas = 0;
        int totalCost = 0;

        for (int i = 0; i < gas.size(); i++)
        {
            totalGas += gas[i];
        }

        for (int i = 0; i < cost.size(); i++)
        {
            totalCost += cost[i];
        }

        if (totalGas < totalCost)
        {
            return -1;
        }

        int startIndex = 0;
        int gasRemaining = 0;

        for (int i = 0; i < gas.size(); i++)
        {
            gasRemaining += gas[i] - cost[i];
            if (gasRemaining < 0)
            {
                startIndex = i + 1;
                gasRemaining = 0;
            }
        }

        return startIndex;
    }
};

// Time Complexity: O(n), where n is the length of the input arrays gas and cost, since we are iterating through the arrays once.
// Space complxity : O(1), since we are using only a constant amount of extra space for variables totalGas, totalCost, startIndex, and gasRemaining.

// If totalgas available is less than total gas need to form a loop travel -> return -1
// find the starting point;
// go to each index, and check whether this can be startIndex, if not startIndex = i+1 (maybe next one can be?), gasRemaining = 0.

// if you reach till end with positive remaining, obviously you can complete.
