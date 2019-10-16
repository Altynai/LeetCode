class Solution {
private:
    bool valid(map<int, int> values) {
        auto it = values.begin();
        pair<int, int> a = *(it++);
        if (values.size() == 1) {
            return (a.first == 1) || (a.second == 1);
        } else if (values.size() == 2) {
            pair<int, int> b = *it;
            if (a.first > b.first)
                swap(a, b);
            return (a.first == 1 && a.second == 1) || (b.second == 1 && a.first + 1 == b.first);
        }
        return false;
    }

public:
    int maxEqualFreq(vector<int>& nums) {
        map<int, int> times, values;
        int n = nums.size(), ans = 0;
        for (int i = 0; i < n; i++) {
            int m = times[nums[i]]++;
            values[m + 1]++;
            if (m > 0 && --values[m] == 0)
                values.erase(m);
            if (valid(values))
                ans = i + 1;
        }
        return ans;
    }
};
