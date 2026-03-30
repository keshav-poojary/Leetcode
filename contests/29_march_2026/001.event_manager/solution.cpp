#include<bits/stdc++.h>
using namespace std;
class EventManager {
public:
    // -prioirty _bcs default store asc to desc) -> need highest prioirty
    // <-priority, eventId>
    set<pair<int, int>> s;
    unordered_map<int, int> mp;
    EventManager(vector<vector<int>>& events) {
        for (auto& e : events) {
            int eventId = e[0];
            int priority = e[1];
            mp[eventId] = priority;
            s.insert({-priority, eventId});
        }
    }

    void updatePriority(int eventId, int newPriority) {
        if (mp.find(eventId) == mp.end())
            return;

        int currentPriority = mp[eventId];
        s.erase({-currentPriority, eventId});

        mp[eventId] = newPriority;
        s.insert({-newPriority, eventId});
    }

    int pollHighest() {
        if (s.empty()) {
            return -1;
        }
        auto top = s.begin();
        int id = top->second;
        s.erase(top);
        mp.erase(id);
        return id;
    }
};

/**
 * Your EventManager object will be instantiated and called as such:
 * EventManager* obj = new EventManager(events);
 * obj->updatePriority(eventId,newPriority);
 * int param_2 = obj->pollHighest();
 */