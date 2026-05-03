#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {

        //{position,time}  - time = (target-position)/speed
        vector<pair<int, double>> cars;

        for (int i = 0; i < position.size(); i++) {
            double time = (double)(target - position[i]) / speed[i];
            cars.push_back({position[i], time});
        }

        stack<double> s;

        sort(cars.begin(), cars.end(), greater<pair<int, int>>());

        for (int i = 0; i < cars.size(); i++) {
            if (s.empty() || s.top() < cars[i].second) {
                s.push(cars[i].second);
            }
        }

        return s.size();
    }
};

// Time Complexity: O(nlogn) - sorting
// Space Complexity: O(n) - stack and cars vector

// Explanation:
// 1. We create a vector of pairs to store the position and time taken for each car to reach the target.
// 2. We sort the cars based on their position in descending order.
// 3. We use a stack to keep track of the time taken for the fleets. If the current car's time is greater than the top of the stack, it means it will form a new fleet, so we push its time onto the stack.
// 4. Finally, the size of the stack will give us the number of fleets that will arrive at the target.