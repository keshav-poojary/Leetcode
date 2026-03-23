#include <vector>
#include <map>
using namespace std;

class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        map<int, int> mp;

        for (int i = 0; i < nums.size(); i++) {
            if (mp.find(nums[i]) != mp.end()) {
                if (i - mp[nums[i]] <= k) {
                    return true;
                }
            }

            mp[nums[i]] = i;
        }

        return false;
    }
};

// Time Complexity: O(n) where n is the length of the input array.
// Space Complexity: O(n) in the worst case when all elements are distinct and we store them in the map.