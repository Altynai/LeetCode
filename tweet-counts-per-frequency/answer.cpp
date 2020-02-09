class TweetCounts {
private:
    map<string, multiset<int>> db;

public:
    TweetCounts() {
        db.clear();
    }

    void recordTweet(string tweetName, int time) {
        db[tweetName].insert(time);
    }
    
    vector<int> getTweetCountsPerFrequency(string freq, string tweetName, int startTime, int endTime) {
        if (db.count(tweetName) == 0) return {};

        multiset<int>& times = db[tweetName];
        int interval = 60;
        if (freq == "hour") interval = 3600;
        if (freq == "day") interval = 3600 * 24;
        
        vector<int> ans;
        endTime += 1;
        while (startTime < endTime) {
            int s = startTime, e = min(endTime, startTime + interval);
            ans.push_back(distance(times.lower_bound(s), times.lower_bound(e)));
            startTime = e;
        }
        return ans;
    }
};

/**
 * Your TweetCounts object will be instantiated and called as such:
 * TweetCounts* obj = new TweetCounts();
 * obj->recordTweet(tweetName,time);
 * vector<int> param_2 = obj->getTweetCountsPerFrequency(freq,tweetName,startTime,endTime);
 */
