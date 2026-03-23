#include <bits/stdc++.h>
#include <vector>
using namespace std;

class Solution {
public:
    int countKeyChanges(string s) {
        for (int i = 0; i < s.size(); i++) {
            s[i] = tolower(s[i]);
        }

        int count = 0;
        for (int i = 0; i < s.size() -1; i++) {
            if (s[i] != s[i + 1]) {
                count++;
            }
        }

        return count;
    }
};
// Time Complexity: O(n) where n is the length of the input string.
// Space Complexity: O(1) as we are using only a constant amount of extra space