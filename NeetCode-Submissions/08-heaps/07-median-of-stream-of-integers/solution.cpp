#include <bits/stdc++.h>
using namespace std;

class MedianFinder
{
public:
    // initialize maxheap and minheap
    priority_queue<int> maxheap;
    priority_queue<int, vector<int>, greater<int>> minheap;

    MedianFinder()
    {
    }

    void addNum(int x)
    {

        if (maxheap.size() == 0 || x < maxheap.top())
        {
            maxheap.push(x);
        }
        else
        {
            minheap.push(x);
        }

        balance();
    }

    void balance()
    {
        if (maxheap.size() > minheap.size() + 1)
        {
            minheap.push(maxheap.top());
            maxheap.pop();
        }
        else if (minheap.size() > maxheap.size() + 1)
        {
            maxheap.push(minheap.top());
            minheap.pop();
        }
    }

    double findMedian()
    {

        if (maxheap.size() == minheap.size())
        {
            if (maxheap.empty())
                return 0; // the first case where we did not input any number and directly asked for a median.
            else
                return (double)(maxheap.top() + minheap.top()) / 2.0;
            // because median is the average of 2 middles when length is even
        }
        else
        {
            // if the size is not equal then return the top of the largest heap simply
            if (maxheap.size() > minheap.size())
                return maxheap.top();
            else
                return minheap.top();
        }
    }
};
