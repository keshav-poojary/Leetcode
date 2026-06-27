#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int maxNumberOfBalloons(string text)
    {
        map<char, int> mp;

        for (int i = 0; i < text.size(); i++)
        {
            mp[text[i]]++;
        }

        int count = 0;

        while (true)
        {
            if (mp['b'] < 1 || mp['a'] < 1 || mp['l'] < 2 || mp['o'] < 2 ||
                mp['n'] < 1)
            {
                break;
            }

            mp['b']--;
            mp['a']--;
            mp['l']--;
            mp['l']--;
            mp['o']--;
            mp['o']--;
            mp['n']--;

            count++;
        }

        return count;
    }
};

// Time Complexity: O(n)
// Space Complexity: O(1)