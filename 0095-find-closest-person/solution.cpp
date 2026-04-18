#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int findClosest(int x, int y, int z)
    {
        int person1Diff = abs(x - z);
        int person2diff = abs(y - z);

        if (person1Diff == person2diff)
        {
            return 0;
        }
        else if (person1Diff < person2diff)
        {
            return 1;
        }
        else
        {
            return 2;
        }
    }
};