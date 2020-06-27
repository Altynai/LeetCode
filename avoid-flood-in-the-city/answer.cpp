class Solution {
public:
    vector<int> avoidFlood(vector<int>& rains) {
        int n = rains.size();
        map<int, int> last;

        vector<int> ans(n, -1);
        set<int> zeros;

        for(int i = 0; i < n; i++) {
            if (rains[i] > 0)
                last[rains[i]] = -1;
        }
        
        for(int i = 0; i < n; i++) {
            if (rains[i] == 0) {
                zeros.insert(i);
                continue;
            }

            if (last[rains[i]] == -1)
                last[rains[i]] = i;
            else {
                int x = last[rains[i]];
                int y = i;
                auto it = zeros.lower_bound(x + 1);
                if (it == zeros.end())
                    return {};
                
                int p = *it;
                ans[p] = rains[i];
                zeros.erase(it);
                last[rains[i]] = i;
            }
        }

        for(int i = 0; i < n; i++) {
            if (rains[i] == 0 && ans[i] == -1)
                ans[i] = 1;
        }
        return ans;
    }
};
