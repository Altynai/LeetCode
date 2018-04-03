#define PII pair<int, int>

bool compare(const PII& lh, const PII& rh) {
    if (lh.first != rh.first)
        return lh.first < rh.first;
    return lh.second < rh.second;
}

class Solution {
public:
    int leastBricks(vector<vector<int>>& wall) {
        vector<PII > pairs;
        for (auto row : wall) {
            int start = 0;
            for (int i = 0; i < row.size(); i++) {
                if (i > 0)
                    pairs.push_back(make_pair(start, 1));
                if (i + 1 < row.size())
                    pairs.push_back(make_pair(start + row[i], -1));
                start += row[i];
            }
        }
        sort(pairs.begin(), pairs.end(), compare);
        int best = wall.size(), sum = wall.size(), index = 0;
        for (int i = 0; i < pairs.size(); i++) {
            sum += pairs[i].second;
            best = min(best, sum);
        }
        return best;
    }
};