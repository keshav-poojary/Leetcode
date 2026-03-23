class Solution {
public:
    int xorOperation(int n, int start) {
        int res = 0;
        for (int i = 0; i < n; i++) {
            res = res ^ (start + 2 * i);
        }
        return res;
    }
};

// Time Complexity: O(n) where n is the number of elements in the input array.
// Space Complexity: O(1) as we are using only a constant amount of extra space