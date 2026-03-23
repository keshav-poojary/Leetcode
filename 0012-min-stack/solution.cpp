#include <stack>
using namespace std;

// Solution 1: Using two stacks
class MinStack {
    stack<int> s, minstack;
public:
    MinStack() {}

    void push(int val) {
        if (s.empty()) {
            s.push(val);
            minstack.push(val);
        } else {
            s.push(val);
            if (minstack.top() >= val) {
                minstack.push(val);
            }
        }
    }

    void pop() {
        if (s.top() == minstack.top()) {
            minstack.pop();
        }
        s.pop();
    }

    int top() { return s.top(); }

    int getMin() { return minstack.top(); }
};


// Time Complexity: O(1) for all operations (push, pop, top, getMin).
// Space Complexity: O(n) in the worst case when all elements are the same and we store them in the minstack.

// Solution 2: Using a single stack to store pairs of (value, current minimum)
class Solution {
     stack<pair<int,int>>s;
     public:

     void push(int val){
           if(s.empty()){
            s.push({val, val});
           }else{
            s.push({val, min(val, s.top().first)});
           }
     }

     void pop(){
        s.pop();
     }

     int top(){
        return s.top().first;
     }

     int mini(){
        return s.top().second;
     }
};

// Time Complexity: O(1) for all operations (push, pop, top, mini).
// Space Complexity: O(n) in the worst case when all elements are distinct and we store