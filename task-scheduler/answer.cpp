class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        if (tasks.size() == 0)
            return 0;
        map<char, int> counter;
        for (auto task : tasks)
            counter[task]++;
        vector< pair<int, char> > pairs;
        for (auto it : counter)
            pairs.push_back(make_pair(it.second, it.first));
        sort(pairs.begin(), pairs.end());
        map<char, int> lastUsed;
        int count = 0;
        while (pairs.size() > 0) {
            bool found = false;
            for (int i = pairs.size() - 1; i >= 0; i--) {
                auto it = lastUsed.find(pairs[i].second);
                // not used
                if (it == lastUsed.end()) {
                    found = true;
                } else if (count - (it->second) > n) {
                    found = true;
                }

                if (found) {
                    // remove
                    lastUsed[pairs[i].second] = count;
                    if (pairs[i].first == 1)
                        pairs.erase(pairs.begin() + i);
                    else
                        pairs[i] = make_pair(pairs[i].first - 1, pairs[i].second);
                    // resort
                    while (i - 1 >= 0 && pairs[i].first < pairs[i - 1].first) {
                        swap(pairs[i], pairs[i - 1]);
                        i--;
                    }
                    break;
                }
                // idle
            }
            count++;
        }
        return count;
    }
};