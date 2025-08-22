class Twitter {
private:
    int timestamp;
    unordered_map<int, unordered_set<int>> following;
    unordered_map<int, vector<pair<int, int>>> tweets;

public:
    Twitter() {
        timestamp = 0;
    }

    void postTweet(int userId, int tweetId) {
        tweets[userId].push_back({timestamp++, tweetId});
    }

    vector<int> getNewsFeed(int userId) {
        priority_queue<pair<int, int>> pq;
        if (tweets.count(userId)) {
            for (auto &tweet : tweets[userId]) {
                pq.push(tweet);
            }
        }

        for (int followeeId : following[userId]) {
            if (tweets.count(followeeId)) {
                for (auto &tweet : tweets[followeeId]) {
                    pq.push(tweet);
                }
            }
        }

        vector<int> res;
        int count = 0;
        while (!pq.empty() && count < 10) {
            res.push_back(pq.top().second);
            pq.pop();
            count++;
        }
        return res;
    }

    void follow(int followerId, int followeeId) {
        if (followerId == followeeId) return;
        following[followerId].insert(followeeId);
    }

    void unfollow(int followerId, int followeeId) {
        if (following.count(followerId)) {
            following[followerId].erase(followeeId);
        }
    }
};
