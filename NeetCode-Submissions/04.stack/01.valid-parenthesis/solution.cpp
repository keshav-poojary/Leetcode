#include <stack>
#include <string>
using namespace std;
class Solution {
public:
    bool isValid(string s) {
        stack<char> st;

        for (int i = 0; i < s.size(); i++) {
            char ch = s[i];

            if (ch == '(' || ch == '{' || ch == '[') {
                st.push(ch);
            } else {
                if (st.empty()) {
                    return false;
                }
                if (ch == ')' && st.top() == '(') {
                    st.pop();
                } else if (ch == '}' && st.top() == '{') {
                    st.pop();
                } else if (ch == ']' && st.top() == '[') {
                    st.pop();
                } else {
                    return false;
                }
            }
        }

        if (st.empty()) {
            return true;
        }

        return false;
    }
};

// Time Complexity: O(n) where n is the length of the input string, since we need to iterate through the string once to check for valid parentheses.
// Space Complexity: O(n) in the worst case when all characters in the string are opening