#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int minMeetingRooms(vector<int> &start, vector<int> &end)
    {
        map<int, int> events;
        for (int i = 0; i < start.size(); i++)
        {
            events[start[i]]++;
            events[end[i]]--;
        }
        // sort(events.begin(), events.end());

        int overlaps = 0;
        int maxiOverlaps = 0;

        for (auto eve : events)
        {
            overlaps += eve.second;
            maxiOverlaps = max(maxiOverlaps, overlaps);
        }

        return maxiOverlaps;
    }
};
