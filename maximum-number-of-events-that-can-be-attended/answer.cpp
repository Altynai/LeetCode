class Solution {
public:
    int maxEvents(vector<vector<int>>& events) {
        sort(events.begin(), events.end(), [](const auto& lhs, const auto& rhs) {
            return lhs[0] < rhs[0];
        });

        int n = events.size(), l = -1, r = 0;
        priority_queue<int, vector<int>, greater<int>> pq;
        for (int i = 0; i < n; i++) {
            l = (l == -1 || events[i][0] < l) ? events[i][0] : l;
            r = max(events[i][1], r);
        }

        int ans = 0, i = 0;
        for (int d = l; d <= r; d++) {
            while (i < n && events[i][0] == d)
                pq.push(events[i++][1]);
            while (!pq.empty() and pq.top() < d)
                pq.pop();
            if (!pq.empty()) {
                pq.pop();
                ans++;
            }
        }
        return ans;
    }
};
