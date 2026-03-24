#include <queue>
using namespace std;
class Solution {
public:
    int timeRequiredToBuy(vector<int>& tickets, int k) {
        queue<pair<int, int>> q;

        for (int i = 0; i < tickets.size(); i++) {
            q.push({i, tickets[i]});
        }

        int count = 0;
        while (!q.empty()) {
            int person = q.front().first;
            int personTicket = q.front().second;
            q.pop();

            personTicket--;
            count++;

            if (personTicket == 0 && person == k) {
                break;
            }

            if (personTicket > 0) {
                q.push({person, personTicket});
            }
        }

        return count;
    }
};