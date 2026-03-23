#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
        int mini = INT_MAX;
        int n = arr.size();

        vector<vector<int>> res;
        // step 1 : sort it
        sort(arr.begin(), arr.end());

        //find minimal diff
        for (int i = 1; i < n; i++) {
            mini = min(mini, abs(arr[i] - arr[i - 1]));
        }

        //check if any diff can be minimal result
        for (int i = 1; i < n; i++) {
            if (abs(arr[i] - arr[i - 1]) == mini) {
                res.push_back({arr[i - 1], arr[i]});
            }
        }

        return res;
    }
};

// Time Complexity: O(n log n) where n is the length of the input array due to the sorting step.
// Space Complexity: O(1) if we ignore the space used for the output, otherwise O(n) in the worst case when all pairs have the same minimum absolute difference and we store them in the result vector.