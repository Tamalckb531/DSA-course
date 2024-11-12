#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>
using namespace std;

class Twitter
{
    //? custom data structure for storing tweet with timestamp
    struct Tweet
    {
        int tweetId;
        int time;

        Tweet(int id, int t)
        {
            tweetId = id;
            time = t;
        }
    };

    //? Global clock for all tweet
    int globalTime;

    //? map for storing all tweet of a specific user
    unordered_map<int, vector<Tweet>> userTweet; // {userId,{...tweet}} format

    //? map for storing all followings of a specific user
    //* unordered_set as we need to follow on user only once
    unordered_map<int, unordered_set<int>> followings; // {userId, {...followeeId}} format

    //? custom comparator for storing the latest tweet on minHeap
    class comp
    {
    public:
        bool operator()(const Tweet &a, const Tweet &b)
        {
            return a.time > b.time; //* will return the bigger time tweet or the latest tweet
        }
    };

public:
    Twitter()
    {
        globalTime = 0; //* init for global time when twitter start
    }

    void postTweet(int userId, int tweetId)
    {
        userTweet[userId].push_back(Tweet(tweetId, globalTime));
        globalTime++;
    }

    vector<int> getNewsFeed(int userId)
    {
        priority_queue<Tweet, vector<Tweet>, comp> minHeapTweet;

        //? get all the tweet of the user
        if (userTweet.find(userId) != userTweet.end())
        {
            for (auto tweet : userTweet[userId])
            {
                minHeapTweet.push(tweet);
                if (minHeapTweet.size() > 10)
                {
                    minHeapTweet.pop();
                }
            }
        }

        //? get all the tweet of the followee of user
        if (followings.find(userId) != followings.end())
        {
            auto userFollowee = followings[userId];
            for (auto followeeId : userFollowee)
            {
                if (userTweet.find(followeeId) != userTweet.end())
                {
                    for (auto tweet : userTweet[followeeId])
                    {
                        minHeapTweet.push(tweet);
                        if (minHeapTweet.size() > 10)
                            minHeapTweet.pop();
                    }
                }
            }
        }

        //? store all the latest tweet in a vector and return
        vector<int> latestTweet;
        while (!minHeapTweet.empty())
        {
            auto tweet = minHeapTweet.top();
            minHeapTweet.pop();
            latestTweet.push_back(tweet.tweetId);
        }
        reverse(latestTweet.begin(), latestTweet.end()); //? the oldest one will be in the top but we need the latest one in the top so we reverse it
        return latestTweet;
    }

    void follow(int followerId, int followeeId)
    {
        if (followerId == followeeId)
            return; //* user can't follow themselves
        followings[followerId].insert(followeeId);
    }

    void unfollow(int followerId, int followeeId)
    {
        if (followings.find(followerId) != followings.end())
        {
            followings[followerId].erase(followeeId);
        }
    }
};
