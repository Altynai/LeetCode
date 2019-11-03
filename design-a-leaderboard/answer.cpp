class Leaderboard {
private:
    map<int, int> s;

public:
    Leaderboard() {
        s.clear();
    }
    
    void addScore(int playerId, int score) {
        s[playerId] += score;
    }
    
    int top(int K) {
        priority_queue<int, vector<int>, greater<int>> pq;
        int sum = 0;
        for (auto const& item : s) {
            pq.push(item.second);
            sum += item.second;
            if (pq.size() > K) {
                sum -= pq.top();
                pq.pop();
            }
        }
        return sum;
    }
    
    void reset(int playerId) {
        s[playerId] = 0;
    }
};

/**
 * Your Leaderboard object will be instantiated and called as such:
 * Leaderboard* obj = new Leaderboard();
 * obj->addScore(playerId,score);
 * int param_2 = obj->top(K);
 * obj->reset(playerId);
 */
