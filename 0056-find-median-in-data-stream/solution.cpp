#include <queue>
using namespace std;

class MedianFinder
{
public:
    // max heap
    priority_queue<int> maxHeap;
    // min heap
    priority_queue<int, vector<int>, greater<int>> minHeap;

    MedianFinder() {}

    void addNum(int num)
    {
        if (maxHeap.size() == 0 || num < maxHeap.top())
        {
            maxHeap.push(num);
        }
        else
        {
            minHeap.push(num);
        }

        balance();
    }

    void balance()
    {
        if (maxHeap.size() > minHeap.size() + 1)
        {
            minHeap.push(maxHeap.top());
            maxHeap.pop();
        }

        if (minHeap.size() > maxHeap.size() + 1)
        {
            maxHeap.push(minHeap.top());
            minHeap.pop();
        }
    }

    double findMedian()
    {
        if (minHeap.size() == maxHeap.size())
        {
            double res = (maxHeap.top() + minHeap.top()) / 2.0;
            return res;
        }
        else
        {
            if (maxHeap.size() > minHeap.size())
            {
                return maxHeap.top();
            }
            else
            {
                return minHeap.top();
            }
        }
    }
};

// Time Complexity: O(log n) for addNum and O(1) for findMedian
// Space Complexity: O(n) for storing the numbers in the heaps