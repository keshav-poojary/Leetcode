#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool canBeEqual(string s1, string s2) {
        // check for even position
        bool even = (s1[0] == s2[0] || s1[0] == s2[2]) &&
                    (s1[2] == s2[2] || s2[0] == s1[2]);

        // check for odd positions
        bool odd = (s1[1] == s2[1] || s1[1] == s2[3]) &&
                   (s1[3] == s2[3] || s1[3] == s2[1]);
        return even && odd;
    }
};

// check for even if s1[0] == s2[0] ok same, or we can swap s1[0] == s2[2]
//                  if s1[2] == s2[2] ok same, or we can swap s1[2] == s2[0]
// check for odd if s1[1] == s2[1] ok same, or we can swap s1[1] == s2[3]
//               if s1[3] == s2[3] ok same, or we can swap s1[3] == s2[1]