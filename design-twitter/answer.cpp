
int unixstamp = 0;

int currentTime() {
    return unixstamp++;
}

struct Tweet {
    int id;
    int tweetedAt;

    Tweet(int id) {
        this->id = id;
        tweetedAt = currentTime();
    }

    const bool operator<(const Tweet& rh) const {
        return tweetedAt < rh.tweetedAt;
    }
};

struct User {
    vector<Tweet> tweets;
    set<int> follows;
    int id;

    User(int id) {
        this->id = id;
        tweets = vector<Tweet>();
        follows = set<int>();
        follows.insert(id);
    }

    void postTweet(int tweetId) {
        tweets.push_back(Tweet(tweetId));
    }

    void follow(int followeeId) {
        follows.insert(followeeId);
    }

    void unfollow(int followeeId) {
        if (followeeId != id)
            follows.erase(followeeId);
    }
};

class Twitter {
private:
    map<int, User*> users;

    User* getUser(int userId) {
        map<int, User*>::iterator it = users.find(userId);
        User* user = NULL;
        if (it == users.end()) {
            user = new User(userId);
            users[userId] = user;
        } else
            user = it->second;
        return user;
    }

public:
    /** Initialize your data structure here. */
    Twitter() {
        users = map<int, User*>();
    }

    /** Compose a new tweet. */
    void postTweet(int userId, int tweetId) {
        User* user = getUser(userId);
        user->postTweet(tweetId);
    }

    /** Retrieve the 10 most recent tweet ids in the user's news feed. Each item in the news feed must be posted by users who the user followed or by the user herself. Tweets must be ordered from most recent to least recent. */
    vector<int> getNewsFeed(int userId) {
        // init
        vector<User*> followees;
        vector<int> indexes;
        User* user = getUser(userId);
        set<int>::iterator it;
        for (it = user->follows.begin(); it != user->follows.end(); it++) {
            User* followee = getUser(*it);
            followees.push_back(followee);
            indexes.push_back(followee->tweets.size() - 1);
        }

        // query
        priority_queue<pair<Tweet, int> > q;
        for (int i = 0; i < followees.size(); ++i) {
            User* user = followees[i];
            int index = indexes[i];
            if (index < 0)
                continue;
            Tweet tweet = user->tweets[index];
            indexes[i]--;
            pair<Tweet, int> item = make_pair(tweet, i);
            q.push(item);
        }
        vector<int> feedIds;
        for (int i = 0; i < 10; ++i) {
            if (q.empty())
                continue;
            pair<Tweet, int> item = q.top();
            q.pop();
            feedIds.push_back(item.first.id);
            int j = item.second;
            int index = indexes[j];
            if (index >= 0) {
                User* user = followees[j];
                Tweet tweet = user->tweets[index];
                pair<Tweet, int> item = make_pair(tweet, j);
                q.push(item);
                indexes[j]--;
            }
        }
        return feedIds;
    }

    /** Follower follows a followee. If the operation is invalid, it should be a no-op. */
    void follow(int followerId, int followeeId) {
        User* follower = getUser(followerId);
        User *followee = getUser(followeeId);
        follower->follow(followeeId);
    }

    /** Follower unfollows a followee. If the operation is invalid, it should be a no-op. */
    void unfollow(int followerId, int followeeId) {
        User* follower = getUser(followerId);
        User *followee = getUser(followeeId);
        follower->unfollow(followeeId);
    }
};

/**
 * Your Twitter object will be instantiated and called as such:
 * Twitter obj = new Twitter();
 * obj.postTweet(userId,tweetId);
 * vector<int> param_2 = obj.getNewsFeed(userId);
 * obj.follow(followerId,followeeId);
 * obj.unfollow(followerId,followeeId);
 */