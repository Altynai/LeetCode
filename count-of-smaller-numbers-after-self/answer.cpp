
bool compare(const pair<int, int>& lh, const pair<int, int>& rh) {
    if (lh.first == rh.first) {
        return lh.second > rh.second;
    } else {
        return lh.first < rh.first;
    }
}

class Solution {
private:
    int n;
    vector<int> bit; // binary indexed tree
    vector<pair<int, int> > items;

    int sum(int i) {
        int answer = 0;
        while (i >= 1) {
            answer += bit[i];
            i -= i & -i;
        }
        return answer;
    }

    void update(int i, int value) {
        while (i <= n) {
            bit[i] += value;
            i += i & -i;
        }
    }

    void init(vector<int>& nums) {
        n = nums.size();
        bit = std::vector<int>(n + 1, 0);
        items = std::vector<pair<int, int> >(n);
        std::reverse(nums.begin(), nums.end());
        for (int i = 0; i < n; ++i)
            items[i] = make_pair(nums[i], i);
    }

    vector<int> solve() {
        std::sort(items.begin(), items.end(), compare);
        vector<int> answer(n, 0);
        for (int i = 0; i < n; i++) {
            int index = items[i].second; // 0 based
            int value = items[i].first;
            answer[index] = sum(index + 1);
            update(index + 1, 1);
        }
        std::reverse(answer.begin(), answer.end());
        return answer;
    }
public:
    vector<int> countSmaller(vector<int>& nums) {
        init(nums);
        return solve();
    }
};