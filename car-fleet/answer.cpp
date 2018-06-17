#define PII pair<int, int>
#define MP(a, b) make_pair(a, b)

class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        vector<PII> items;
        int n = position.size();
        if (n == 0)
            return 0;
        for (int i = 0; i < n; i++)
            items.push_back(MP(position[i], speed[i]));
        sort(items.begin(), items.end());
        reverse(items.begin(), items.end());
        int fleet = 1, m = 0;
        for (int i = 1; i < n; i++) {
            int prePos = items[m].first;
            int preSpeed = items[m].second;
            int curPos = items[i].first;
            int curSpeed = items[i].second;
            if (curSpeed < preSpeed) {
                fleet++;
                m = i;
            } else if (curSpeed == preSpeed) {
                if (prePos != curPos) {
                    fleet++;
                    m = i;
                }
            } else {
                double preTime = (double)(target - prePos) / preSpeed;
                double where = preTime * curSpeed + curPos;
                if (where < target) {
                    fleet++;
                    m = i;
                }
            }
        }
        return fleet;
    }
};
