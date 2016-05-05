#define i64 long long

class Solution {
private:
    vector<i64> bit;
    int n;

    i64 sumValue(int i) {
        i64 answer = 0;
        while (i >= 1) {
            answer += bit[i];
            i -= i & (-i);
        }
        return answer;
    }

    void setValue(int i, i64 value) {
        i64 old = this->sumValue(i) - this->sumValue(i - 1);
        i64 change = value - old;
        int n = bit.size() - 1;
        while (i <= n) {
            bit[i] += change;
            i += i & (-i);
        }
    }

public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
        if (k == 0 || t < 0)
            return false;
        this->n = nums.size();
        this->bit = std::vector<i64>(1 + this->n, 0);
        std::vector<pair<i64,int> > ia;
        for (int i = 0; i < n; ++i)
            ia.push_back(make_pair((i64)nums[i], i + 1));
        std::sort(ia.begin(), ia.end());
        int low = 0, high = 0;
        for (int i = 0; i < n; ++i) {
            while (low < i && ia[i].first - ia[low].first > (i64)t) {
                if (low == high)
                    high++;
                this->setValue(ia[low++].second, 0);
            }
            while (high < n && std::abs(ia[high].first - ia[i].first) <= (i64)t)
                this->setValue(ia[high++].second, 1);
            int x = min(ia[i].second + k, n);
            int y = ia[i].second - k;
            if (sumValue(x) - sumValue(y - 1) >= 2)
                return true;
        }
        return false;
    }
};