#include <bits/stdc++.h>
#include <vector>
using namespace std;
class Solution
{
public:
    vector<int> findWordsContaining(vector<string> &words, char x)
    {
        vector<int> res;

        for (int i = 0; i < words.size(); i++)
        {
            for (char c : words[i])
            {
                if (c == x)
                {
                    res.push_back(i);
                    break;
                }
            }
        }

        return res;
    }
};

// Time Complexity: O(n*m) where n is the number of words and m is the average length of each word.
// Space Complexity: O(k) where k is the number of words that contain the character x