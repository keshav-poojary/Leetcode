#include <vector>
using namespace std;
class Solution {
public:
    int longestMountain(vector<int>& arr) {
        int maxi = 0;
        int n = arr.size();

        for (int i = 1; i <= n - 2; i++) {
            // check for peak point
            if (arr[i] > arr[i - 1] && arr[i] > arr[i + 1]) {
                int count = 1;
                int left = i, right = i;

                // go to left
                while (left > 0 && arr[left] > arr[left - 1]) {
                    count++;
                    left--;
                }

                // to to right
                while (right < n - 1 && arr[right] > arr[right + 1]) {
                    count++;
                    right++;
                }

                maxi = max(count, maxi);
            } 
        }
        return maxi;
    }
};

// Time Complexity: O(n) where n is the length of the input array.
// Space Complexity: O(1) as we are using only a constant amount of extra space