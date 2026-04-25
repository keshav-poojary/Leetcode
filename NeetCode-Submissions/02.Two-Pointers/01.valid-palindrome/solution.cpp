#include <string>
using namespace std;

class Solution
{
public:
    bool isPalindrome(string s)
    {
        string str = "";

        for (auto data : s)
        {
            if (isalnum(data))
            {
                str += tolower(data);
            }
        }

        int low = 0;
        int high = str.size() - 1;

        while (low < high)
        {
            if (str[low] != str[high])
            {
                return false;
            }

            low++;
            high--;
        }

        return true;
    }
};

// Time Complexity: O(n) where n is the length of the input string, since we need to iterate through the string to create the filtered version and then check for palindrome
// Space Complexity: O(n) where n is the length of the input string, since we create a new string to store the filtered version of the input string