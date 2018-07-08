class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int cnt[21] = {0}, n = bills.size();
        for (int i = 0; i < n; i++) {
            if (bills[i] == 5)
                cnt[5]++;
            else if (bills[i] == 10) {
                if (cnt[5] == 0) return false;
                cnt[5]--;
                cnt[10]++;
            } else {
                if (cnt[10] > 0 && cnt[5] > 0)
                    cnt[10]--, cnt[5]--;
                else if (cnt[10] == 0 && cnt[5] >= 3)
                    cnt[5] -= 3;
                else
                    return false;
            }
        }
        return true;
    }
};
