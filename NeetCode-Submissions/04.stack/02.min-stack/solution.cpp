
#include <stack>
using namespace std;

class MinStack
{
public:
    stack<int> s, minStack;
    MinStack() {}

    void push(int val)
    {
        if (s.empty())
        {
            s.push(val);
            minStack.push(val);
        }
        else
        {
            if (minStack.top() >= val)
            {
                minStack.push(val);
                s.push(val);
            }
            else
            {
                s.push(val);
            }
        }
    }

    void pop()
    {
        int data = s.top();
        s.pop();
        if (minStack.top() == data)
        {
            minStack.pop();
        }
    }

    int top() { return s.top(); }

    int getMin() { return minStack.top(); }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */

 // Time Complexity: O(1) for all operations (push, pop, top, getMin) since we are using two stacks to maintain the minimum values.
 // Space Complexity: O(n) in the worst case when all elements are pushed onto the stack