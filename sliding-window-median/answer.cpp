class Solution {
private:
    multiset<int> low, high;

    void init() {
        low.clear();
        high.clear();
    }

    void insert(int num) {
        if (low.empty() || num <= *(--low.end())) {
            low.insert(num);
        } else {
            high.insert(num);
        }
    }

    void remove(int num) {
        auto search = low.find(num);
        if (search != low.end())
            low.erase(search);
        else {
            search = high.find(num);
            high.erase(search);
        }
    }

    void balance() {
        while (low.size() > high.size() + 1) {
            auto last = --low.end();
            int value = *last;
            high.insert(value);
            low.erase(last);
        }
        while (high.size() > low.size()) {
            auto first = high.begin();
            int value = *first;
            low.insert(value);
            high.erase(first);
        }
    }

    double median(int k) {
        if (k % 2 == 1) {
            auto last = --low.end();
            return *last;
        }
        else {
            auto last = --low.end();
            auto first = high.begin();
            double s = (double)*last + *first;
            return s / 2;
        }
    }

public:
    vector<double> medianSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();
        k = min(n, k);
        init();
        for (int i = 0; i < k; ++i) {
            insert(nums[i]);
            balance();
        }
        vector<double> ans;
        ans.push_back(median(k));
        for (int i = k; i < n; ++i) {
            int tail = i - k;
            remove(nums[tail]);
            insert(nums[i]);
            balance();
            ans.push_back(median(k));
        }
        return ans;
    }
};