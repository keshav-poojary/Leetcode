#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int leastInterval(vector<char> &tasks, int n)
    {
        map<char, int> mp;

        for (int i = 0; i < tasks.size(); i++)
        {
            mp[tasks[i]]++;
        }

        priority_queue<int> pq;
        for (auto ele : mp)
        {
            pq.push(ele.second);
        }

        int time = 0;

        while (!pq.empty())
        {
            vector<int> temp;

            for (int i = 1; i <= n + 1; i++)
            {
                if (!pq.empty())
                {
                    int ele = pq.top();
                    pq.pop();
                    ele--;
                    temp.push_back(ele);
                }
            }

            for (int i = 0; i < temp.size(); i++)
            {
                if (temp[i] > 0)
                {
                    pq.push(temp[i]);
                }
            }

            if (pq.empty())
            {
                time = time + temp.size();
            }
            else
            {
                time = time + n + 1;
            }
        }

        return time;
    }
};

// Time Complexity: O(T log T) where T is the number of tasks. This is because we are using a priority queue to store the frequencies of the tasks, and we are performing operations on it for each task.
// Space Complexity: O(T) where T is the number of tasks. This is because we are using a priority queue to store the frequencies of the tasks, and in the worst case, all tasks could be different, leading to T entries in the priority queue.