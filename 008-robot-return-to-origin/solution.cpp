#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool judgeCircle(string moves) {
        int position_x = 0;
        int position_y = 0;

        for (int i = 0; i < moves.length(); i++) {
            if (moves[i] == 'U') {
                position_y++;
            } else if (moves[i] == 'D') {
                position_y--;
            } else if (moves[i] == 'R') {
                position_x++;
            } else {
                position_x--;
            }
        }

        return position_x == 0 && position_y == 0;
    }
};

// Time Complexity: O(n) where n is the length of the input string.
// Space Complexity: O(1) as we are using only a constant amount of extra space