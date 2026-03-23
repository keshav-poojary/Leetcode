class Solution {
public:
    int differenceOfSums(int n, int m) {

        int sum1 = 0;
        int sum2 = 0;
        for (int i = 1; i <= n; i++) {
            if (i % m == 0) {
                sum2 = sum2 + i;
            } else {
                sum1 = sum1 + i;
            }
        }
        return sum1 - sum2;
    }
};

// Time Complexity: O(n) where n is the input number.
// Space Complexity: O(1) as we are using only a constant amount of extra space