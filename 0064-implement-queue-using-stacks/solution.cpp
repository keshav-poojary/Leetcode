#include <stack>
using namespace std;
class MyQueue
{
public:
    stack<int> s1;
    stack<int> s2;

    MyQueue() {}

    void push(int x) { s1.push(x); }

    int pop()
    {
        while (!s1.empty())
        {
            s2.push(s1.top());
            s1.pop();
        }
        int data = s2.top();
        s2.pop();

        while (!s2.empty())
        {
            s1.push(s2.top());
            s2.pop();
        }
        return data;
    }

    int peek()
    {
        while (!s1.empty())
        {
            s2.push(s1.top());
            s1.pop();
        }
        int data = s2.top();

        while (!s2.empty())
        {
            s1.push(s2.top());
            s2.pop();
        }

        return data;
    }

    bool empty() { return s1.empty(); }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */

 // time complexity: O(n) for pop and peek, O(1) for push and empty
 // space complexity: O(n) for the two stacks combined