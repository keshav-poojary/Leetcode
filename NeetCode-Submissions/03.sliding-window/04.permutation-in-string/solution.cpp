#include <bits/stdc++.h>
using namespace std;

class Solution
{

public:
    bool checkInclusion(string s1, string s2)
    {
        int n1 = s1.size();
        int n2 = s2.size();

        if (n1 > n2)
        {
            return false;
        }

        sort(s1.begin(), s1.end());

        for (int i = 0; i <= n2 - n1; i = i++)
        {
            string substring = s2.substr(i, n1);
            sort(substring.begin(), substring.end());
            if (substring == s1)
            {
                return true;
            }
        }

        return false;
    }
};

// Time Complexity: O(n1 log n1 + n2 log n1) where n1 is the length of s1 and n2 is the length of s2. Sorting s1 takes O(n1 log n1) time, and for each substring of s2, we sort it in O(n1 log n1) time, resulting in O(n2 log n1) for all substrings.
// Space Complexity: O(n1) for storing the sorted version of s1 and the substring of s2.

class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int n1 = s1.size();
        int n2 = s2.size();

        if (n1 > n2) {
            return false;
        }

        map<char, int> mp1;
        map<char, int> mp2;

        for (int i = 0; i < n1; i++) {
            mp1[s1[i]]++;
        }

        int r = 0;

        while (r <= n2 - n1) {
            mp2.clear();

            for (int i = r; i < r + n1; i++) {
                mp2[s2[i]]++;
            }

            if (mp1 == mp2) {
                return true;
            }
            r++;
        }

        return false;
    }
};

// Time Complexity: O(n1 + n2 * n1) where n1 is the length of s1 and n2 is the length of s2. Building the frequency map for s1 takes O(n1) time, and for each substring of s2, we build a frequency map in O(n1) time, resulting in O(n2 * n1) for all substrings.
// Space Complexity: O(1) since the frequency maps will at most contain 26 characters
