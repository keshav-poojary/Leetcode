#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> s;

        for (int i = 0; i < tokens.size(); i++) {
            if (tokens[i] == "+") {
                int a = s.top();
                s.pop();
                int b = s.top();
                s.pop();
                s.push(a + b);
            } else if (tokens[i] == "-") {
                int a = s.top();
                s.pop();
                int b = s.top();
                s.pop();
                s.push(b - a);
            } else if (tokens[i] == "*") {
                int a = s.top();
                s.pop();
                int b = s.top();
                s.pop();
                s.push(a * b);
            } else if (tokens[i] == "/") {
                int a = s.top();
                s.pop();
                int b = s.top();
                s.pop();
                s.push(b / a);
            } else {
                s.push(stoi(tokens[i]));
            }
        }

        return s.top();
    }
};

// Time Complexity: O(n) where n is the number of tokens in the input vector.
// Space Complexity: O(n) in the worst case when all tokens are numbers and we store