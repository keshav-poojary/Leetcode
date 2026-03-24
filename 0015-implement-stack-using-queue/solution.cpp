#include <queue>
using namespace std;
class MyStack {

    queue<int> q1;
    queue<int> q2;

public:
    MyStack() {}

    void push(int x) {
        if (q1.empty() && q2.empty()) {
            q1.push(x);
        } else {
            while (!q1.empty()) {
                q2.push(q1.front());
                q1.pop();
            }

            q1.push(x);

            while (!q2.empty()) {
                q1.push(q2.front());
                q2.pop();
            }
        }
    }

    int pop() {
        int x = q1.front();
        q1.pop();
        return x;
    }

    int top() { return q1.front(); }

    bool empty() { return q1.empty(); }
};

// Time Complexity: O(n) for push operation, O(1) for pop, top and empty operations.
// Space Complexity: O(n) where n is the number of elements in the stack.