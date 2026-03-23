#include<bits/stdc++.h>
#include<vector>
using namespace std;

class Solution {
public:
    int differenceOfSum(vector<int>& nums) {
        int elementSum = 0;
        int digitSum = 0;
        for (int i = 0; i < nums.size(); i++) {
            elementSum = elementSum + nums[i];
            while (nums[i] > 0) {
                int number = nums[i] % 10;
                digitSum = digitSum + number;
                nums[i] = nums[i] / 10;
            }
        }

        return elementSum - digitSum;
    }
};

// Time Complexity: O(n*m) where n is the number of elements in the input array and m is the average number of digits in each element.
// Space Complexity: O(1) as we are using only a constant amount of extra space