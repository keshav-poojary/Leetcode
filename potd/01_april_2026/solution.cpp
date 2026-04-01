#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    vector<int> survivedRobotsHealths(vector<int>& positions,
                                      vector<int>& healths, string directions) {
        int n = positions.size();
        vector<int> indexes(n, 0);
        stack<int> s;
        vector<int> res;

        for (int i = 0; i < n; i++) {
            indexes[i] = i;
        }

        sort(indexes.begin(), indexes.end(),
             [&](int a, int b) { return positions[a] < positions[b]; });

        for (auto i : indexes) {
            if (directions[i] == 'R') {
                s.push(i);
            } else {
                while (!s.empty() && healths[i] > 0) {
                    if (healths[i] == healths[s.top()]) {
                        healths[i] = 0;
                        healths[s.top()] = 0;
                        s.pop();
                        break;
                    } else if (healths[i] < healths[s.top()]) {
                        healths[i] = 0;
                        healths[s.top()] = healths[s.top()] - 1;
                        break;
                    } else {
                        healths[i] = healths[i] - 1;
                        healths[s.top()] = 0;
                        s.pop();
                    }
                }
            }
        }
        for (int i = 0; i < healths.size(); i++) {
            if (healths[i] > 0) {
                res.push_back(healths[i]);
            }
        }

        return res;
    }
};