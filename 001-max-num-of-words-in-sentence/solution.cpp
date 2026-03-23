#include <bits/stdc++.h>
#include <vector>
using namespace std;
class Solution {
public:
    int mostWordsFound(vector<string>& sentences) {
        int maxi = INT_MIN;
        for (int i = 0; i < sentences.size(); i++) {
            int count = 1;
            for (auto word : sentences[i]) {
                if (word == ' ') {
                    count++;
                }
                maxi = max(maxi, count);
            }
        }
        return maxi;
    }
};

// Time Complexity: O(n*m) where n is the number of sentences and m is the average length of each sentence.
// Space Complexity: O(1) as we are using only a constant amount of extra space