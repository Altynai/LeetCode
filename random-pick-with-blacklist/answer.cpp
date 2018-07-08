class Solution {
private:
    int n;
    vector<int> blacklist;

    int countNotGreaterThan(int num) {
        auto lower = lower_bound(blacklist.begin(), blacklist.end(), num);
        if (lower == blacklist.end())
            return blacklist.size();
        else if (*lower == num)
            return lower - blacklist.begin() + 1;
        return lower - blacklist.begin();
    }

public:
    Solution(int N, vector<int> blacklist) {
        n = N;
        sort(blacklist.begin(), blacklist.end());
        this->blacklist = blacklist;
    }

    int pick() {
        int num = rand() % (n - blacklist.size());
        int low = 0, high = n - 1, ans = 0;
        while (low <= high) {
            int mid = (low + high) >> 1;
            int cnt = mid - countNotGreaterThan(mid);
            if (cnt >= num) {
                ans = mid;
                high = mid - 1;
            } else
                low = mid + 1;
        }
        return ans;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution obj = new Solution(N, blacklist);
 * int param_1 = obj.pick();
 */
