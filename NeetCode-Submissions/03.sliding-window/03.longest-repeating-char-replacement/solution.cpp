#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int findMaxFreq(map<char, int> mp)
    {
        int maxi = 0;

        for (auto m : mp)
        {
            maxi = max(maxi, m.second);
        }

        return maxi;
    }
    int characterReplacement(string s, int k)
    {
        int l = 0;
        int r = 0;
        int n = s.size();

        int maxF = 0;
        int maxL = 0;

        map<char, int> mp;

        while (r < n)
        {
            mp[s[r]]++;
            maxF = findMaxFreq(mp);
            int length = (r - l) + 1;
            if (length - maxF <= k)
            {
                maxL = max(maxL, length);
            }
            else
            {
                mp[s[l]]--;
                l++;
                maxF = findMaxFreq(mp);
            }

            r++;
        }

        return maxL;
    }
};

// algorithm: sliding window + two pointers
//  We maintain a sliding window defined by two pointers, l and r, which represent the left and right boundaries of the current substring. We also maintain a frequency map (mp) to count the occurrences of each character in the current window. The variable maxF keeps track of the maximum frequency of any character in the current window, while maxL keeps track of the length of the longest valid substring found so far.

//  pseudocode:
//  Initialize l and r to 0, maxF and maxL to 0, and an empty frequency map mp.
//  While r is less than the length of the string:
//  Increment the frequency of the character at index r in mp.
//  Update maxF to be the maximum frequency of any character in mp.
//  Calculate the length of the current window (r - l + 1).
//  If the length of the current window minus maxF is less than or equal to k, it means we can replace at most k characters to make all characters in the window the same. In this case, update maxL to be the maximum of maxL and the current window length.
//  If the length of the current window minus maxF is greater than k, it means we need to shrink the window from the left. Decrement the frequency of the character at index l in mp, increment l to move the left pointer, and update maxF again.
//  Increment r to expand the window to the right.

// Time Complexity: O(n) where n is the length of the input string, since we need to iterate through the string once to calculate the longest repeating character replacement
// Space Complexity: O(1) since we are using only a constant amount of extra space to store the frequency of characters in the current window, which can be at most 26 for uppercase letters.