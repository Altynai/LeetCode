
class Solution {
private:
    vector<int> makeVector(int x, int y, int z) {
        int a[3] = {x, y, z};
        return vector<int>(a, a + 3);
    }

    bool inVector(const vector<int> &num, int x) {
        int low = 0, high = num.size() - 1, mid;
        while (low <= high) {
            mid = (low + high) >> 1;
            if (num[mid] == x)
                return true;
            else if (num[mid] < x)
                low = mid + 1;
            else
                high = mid - 1;
        }
        return false;
    }

    void add2result(set<pair<int, int> > &cache, vector<vector<int> > &result, int x, int y, int z) {
        pair<int, int> item = make_pair(x, y);
        if (cache.find(item) != cache.end())
            return;
        cache.insert(item);
        result.push_back(makeVector(x, y, z));
    }

public:
    vector<vector<int> > threeSum(vector<int> &num) {
        vector<int> non_zero;
        vector<vector<int> > result;
        int zero_count = 0;
        for (int i = 0; i < num.size(); ++i) {
            if (num[i] == 0)
                zero_count++;
            else
                non_zero.push_back(num[i]);
        }
        std::sort(non_zero.begin(), non_zero.end());
        set<pair<int, int> > cache;
        int n = non_zero.size();
        // negative + positive + positive
        for (int i = n - 1; i >= 0 && non_zero[i] > 0; i--) {
            int z = non_zero[i];
            for (int j = i - 1; j >= 0 && non_zero[j] > 0; j--) {
                int y = non_zero[j];
                int x = -(non_zero[i] + non_zero[j]);
                if (inVector(non_zero, x))
                	add2result(cache, result, x, y, z);
            }
        }
        // negative + negative + positive
        for (int i = 0; i < n && non_zero[i] < 0; i++) {
            int x = non_zero[i];
            for (int j = i + 1; j < n && non_zero[j] < 0; j++) {
                int y = non_zero[j];
                int z = -(non_zero[i] + non_zero[j]);
                if (inVector(non_zero, z))
                	add2result(cache, result, x, y, z);
            }
        }
        // negative + 0 + positive
        if (zero_count) {
            for (int i = 0; i < n && non_zero[i] < 0; i++) {
                int x = non_zero[i], y = 0, z = -non_zero[i];
                if (inVector(non_zero, z))
                    add2result(cache, result, x, y, z);
            }
        }
        // 0 + 0 + 0
        if (zero_count >= 3)
            result.push_back(makeVector(0, 0, 0));
        return result;
    }
};
