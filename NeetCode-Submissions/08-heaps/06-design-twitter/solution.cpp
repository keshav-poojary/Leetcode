#include <bits/stdc++.h>
using namespace std;

class Twitter
{
public:
    // map of userId to set of followeeIds
    map<int, set<int>> follows;
    // map of userId to vector of pairs of (time, tweetId)
    map<int, vector<pair<int, int>>> tweets;
    int time;

    Twitter() { time = 0; }

    void postTweet(int userId, int tweetId)
    {
        // add the tweet to the user's tweets vector with the current time
        tweets[userId].push_back({time++, tweetId});
    }

    vector<int> getNewsFeed(int userId)
    {
        // use a min heap to store the top 10 most recent tweets from the user and their followees
        priority_queue<pair<int, int>, vector<pair<int, int>>,
                       greater<pair<int, int>>>
            pq;

        // add the user's own tweets to the priority queue
        for (auto tweet : tweets[userId])
        {
            pq.push(tweet);
            if (pq.size() > 10)
            {
                pq.pop();
            }
        }

        // add the tweets of the user's followees to the priority queue
        for (auto follow : follows[userId])
        {
            for (auto tweet : tweets[follow])
            {
                pq.push(tweet);
                if (pq.size() > 10)
                {
                    pq.pop();
                }
            }
        }

        vector<int> res;
        // pop the top 10 most recent tweets from the priority queue and add their tweetIds to the result vector
        while (!pq.empty())
        {
            res.push_back(pq.top().second);
            pq.pop();
        }

        // reverse the result vector to get the most recent tweets first
        reverse(res.begin(), res.end());
        return res;
    }

    void follow(int followerId, int followeeId)
    {
        // add the followeeId to the followerId's set of followees
        follows[followerId].insert(followeeId);
    }

    void unfollow(int followerId, int followeeId)
    {
        // remove the followeeId from the followerId's set of followees
        follows[followerId].erase(followeeId);
    }
};

/**
 * Your Twitter object will be instantiated and called as such:
 * Twitter* obj = new Twitter();
 * obj->postTweet(userId,tweetId);
 * vector<int> param_2 = obj->getNewsFeed(userId);
 * obj->follow(followerId,followeeId);
 * obj->unfollow(followerId,followeeId);
 */