#include <string>
#include <vector>
using namespace std;

class Solution
{
public:
    string mapWordWeights(vector<string> &words, vector<int> &weights)
    {
        string ans;
        for (auto word : words)
        {
            int sum = 0;
            for (auto ch : word)
            {
                sum = sum + weights[ch - 'a'];
            }
            int mod = sum % 26;
            ans += ('z' - mod);
        }

        return ans;
    }
};

// Time Complexity: O(n*m) where n is the number of words and m is the average length of the words.
// Space Complexity: O(n) where n is the number of words.


// Explanation:
// We iterate through each word in the input vector `words`. For each word
// we calculate the sum of the weights of its characters by iterating through each character in the word and adding the corresponding weight from the `weights` vector. We then take the sum modulo 26 to get a value between 0 and 25, which corresponds to a letter in the alphabet. We convert this value to a character by subtracting it from 'z' and appending it to our answer string `ans`. Finally, we return the resulting string.
// The time complexity is O(n*m) because we need to iterate through each word and each character in the word. The space complexity is O(n) because we are storing the resulting string which can be at most the same length as the number of words.