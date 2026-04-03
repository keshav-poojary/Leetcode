#include <vector>
using namespace std;

class Solution
{
public:
    int findTheWinner(int n, int k)
    {
        vector<int> peoples;

        for (int i = 1; i <= n; i++)
        {
            peoples.push_back(i);
        }

        int index = 0;

        while (peoples.size() > 1)
        {
            index = (index + k - 1) % peoples.size();
            peoples.erase(peoples.begin() + index);
        }

        return peoples[0];
    }
};