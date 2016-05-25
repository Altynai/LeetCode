
bool compare(const pair<int, int>& lh, const pair<int, int>& rh) {
    if (lh.first != rh.first)
        return lh.first < rh.first;
    return lh.second > rh.second;
}

class Solution {
private:
    int n;
    vector<pair<int, int> > items;
    vector<int> bits; // binary index tree

    inline int lowbit(int i) {
        return i & (-i);
    }

    void updateMaxValue(int i, int value) {
        while (i <= n) {
            bits[i] = max(bits[i], value);
            i += lowbit(i);
        }
        return;
    }

    int getMaxValue(int i) {
        int value = 0;
        while (i >= 1) {
            value = max(bits[i], value);
            i -= lowbit(i);
        }
        return value;
    }

    void init(vector<int>& nums) {
        n = nums.size();
        if (n == 0)
            return;
        items = vector<pair<int, int> >(n);
        for (int i = 0; i < n; ++i)
            items[i] = make_pair(nums[i], i + 1);
        sort(items.begin(), items.end(), compare);
        bits = vector<int>(n + 1, 0);
    }

    int solve() {
        if (n == 0)
            return n;
        int answer = 0;
        for (int i = 0; i < n; ++i) {
            int value = getMaxValue(items[i].second - 1) + 1;
            answer = max(answer, value);
            updateMaxValue(items[i].second, value);
        }
        return answer;
    }

public:
    int lengthOfLIS(vector<int>& nums) {
        init(nums);
        return solve();
    }
};