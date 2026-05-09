#include <bits/stdc++.h>
using namespace std;

class TimeMap
{
public:
    map<string, vector<pair<string, int>>> mp;

    TimeMap() {}

    void set(string key, string value, int timestamp)
    {
        mp[key].push_back({value, timestamp});
    }

    string findAns(vector<pair<string, int>> &v, int timestamp)
    {
        int low = 0;
        int high = v.size() - 1;
        string ans = "";

        while (low <= high)
        {
            int mid = (low + high) / 2;

            if (v[mid].second <= timestamp)
            {
                ans = v[mid].first;
                low = mid + 1;
            }
            else
            {
                high = mid - 1;
            }
        }

        return ans;
    }

    string get(string key, int timestamp)
    {
        if (mp.find(key) == mp.end())
        {
            return "";
        }
        else
        {
            vector<pair<string, int>> &v = mp[key];
            string ans = findAns(v, timestamp);
            return ans;
        }
    }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */