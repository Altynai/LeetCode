class HitCounter {
public:
    deque<pair<int, int>> line;
    int total;

    /** Initialize your data structure here. */
    HitCounter() {
        line.clear();
        total = 0;
    }

    /** Record a hit.
        @param timestamp - The current timestamp (in seconds granularity). */
    void hit(int timestamp) {
        if (line.empty())
            line.push_front(make_pair(timestamp, 1));
        else {
            pair<int, int>& front = line.front();
            if (front.first == timestamp)
                front.second += 1;
            else
                line.push_front(make_pair(timestamp, 1));
        }
        total += 1;
    }

    /** Return the number of hits in the past 5 minutes.
        @param timestamp - The current timestamp (in seconds granularity). */
    int getHits(int timestamp) {
        int compared = timestamp - 300;
        while (!line.empty() && line.back().first <= compared) {
            pair<int, int> back = line.back();
            total -= back.second;
            line.pop_back();
        }
        return total;
    }
};

/**
 * Your HitCounter object will be instantiated and called as such:
 * HitCounter obj = new HitCounter();
 * obj.hit(timestamp);
 * int param_2 = obj.getHits(timestamp);
 */