#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool isValid(string str) {
        stack<char> s;

        for (auto character : str) {
            if (character == '(' || character == '[' || character == '{') {
                s.push(character);
            } else {
                if (s.empty()) {
                    return false;
                }
                if (character == ']' && s.top() == '[') {
                    s.pop();
                } else if (character == ')' && s.top() == '(') {
                    s.pop();
                } else if (character == '}' && s.top() == '{') {
                    s.pop();
                }else{
                    return false;
                }
            }
        }

        if (s.empty()) {
            return true;
        }

        return false;
    }
};

// Time Complexity: O(n) where n is the length of the input string.
// Space Complexity: O(n) in the worst case when all characters are opening brackets and we