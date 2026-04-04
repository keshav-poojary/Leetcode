#include <vector>
#include <set>
using namespace std;
class Solution
{
public:
    vector<int> recoverOrder(vector<int> &order, vector<int> &friends)
    {
        set<int> s;
        vector<int> ans;

        for (int i = 0; i < friends.size(); i++)
        {
            s.insert(friends[i]);
        }

        for (int i = 0; i < order.size(); i++)
        {
            if (s.find(order[i]) != s.end())
            {
                ans.push_back(order[i]);
            }
        }

        return ans;
    }
};