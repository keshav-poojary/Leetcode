#include <vector>
using namespace std;

class MyCircularQueue
{
public:
    vector<int> cirQueue;
    int front, rear, size;

    MyCircularQueue(int k)
    {
        cirQueue.resize(k);
        front = -1;
        rear = -1;
        size = k;
    }

    bool enQueue(int value)
    {
        if (front == (rear + 1) % size)
            return false;

        rear = (rear + 1) % size;
        cirQueue[rear] = value;
        if (front == -1)
            front = 0;

        return true;
    }

    bool deQueue()
    {
        if (isEmpty())
            return false;

        if (front == rear)
        {
            front = rear = -1;
        }
        else
        {
            front = (front + 1) % size;
        }

        return true;
    }

    int Front()
    {
        if (front == -1)
        {
            return -1;
        }
        return cirQueue[front];
    }

    int Rear()
    {
        if (rear == -1)
        {
            return -1;
        }
        return cirQueue[rear];
    }

    bool isEmpty() { return front == -1; }

    bool isFull() { return (rear + 1) % size == front; }
};

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */