#include <bits/stdc++.h>
#include <vector>
using namespace std;

class Solution {
public:
    string triangleType(vector<int>& nums) {
        if (!((nums[0] + nums[1] > nums[2]) && (nums[0] + nums[2] > nums[1]) &&
              (nums[1] + nums[2] > nums[0]))) {
            return "none";
        }

        if (nums[0] == nums[1] && nums[1] == nums[2] && nums[0] == nums[2]) {
            return "equilateral";
        }

        if (nums[0] != nums[1] && nums[1] != nums[2] && nums[0] != nums[2]) {
            return "scalene";
        }

        return "isosceles";
    }
};

// Time Complexity: O(1) as we are performing a constant number of operations.
// Space Complexity: O(1) as we are using only a constant amount of extra space