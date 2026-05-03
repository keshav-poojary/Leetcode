#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    string minWindow(string s, string t)
    {
        map<char, int> mp;

        for (int i = 0; i < t.size(); i++)
        {
            mp[t[i]]++;
        }

        int l = 0;
        int r = 0;
        int m = s.size();
        int n = t.size();
        int minLength = INT_MAX;
        int startIndex = -1;
        int count = 0;

        while (r < m)
        {
            if (mp[s[r]] > 0)
            {
                count++;
            }

            mp[s[r]]--;

            while (count == n)
            {
                if (r - l + 1 < minLength)
                {
                    minLength = r - l + 1;
                    startIndex = l;
                }

                mp[s[l]]++;

                if (mp[s[l]] > 0)
                {
                    count--;
                }

                l++;
            }

            r++;
        }

        return startIndex == -1 ? "" : s.substr(startIndex, minLength);
    }
};

// Time Complexity: O(m + n), where m is the length of string s and n is the length of string t.
// Space Complexity: O(n), where n is the length of string t, since we are

// pseudo code
// 1. Create a map to store the frequency of characters in string t.
// 2. Initialize two pointers l and r to 0, and variables minLength,
//    startIndex, and count to keep track of the minimum window length, starting index of the minimum window, and the count of characters matched.
// 3. Iterate through string s using the right pointer r:
//    a. If the character at index r is present in the map and its frequency is greater than 0, increment the count.
//    b. Decrement the frequency of the character at index r in the map.
//    c. While the count is equal to the length of string t, it means we have found a valid window:
//       i. Update the minimum window length and starting index if the current window is smaller than the previously found minimum window.
//       ii. Increment the frequency of the character at index l in the map.
//       iii. If the frequency of the character at index l becomes greater than 0, decrement the count.
//       iv. Move the left pointer l to the right.
// 4. After the loop, return the substring of s starting from startIndex with length minLength if a valid window was found, otherwise return an empty string.