
class Solution {
private:
    int pow10(int j) {
        int ans = 1;
        for (int i = 0; i < j; i++)
            ans *= 10;
        return ans;
    }

    vector<int> generate() {
        vector<int> ans = {2, 3, 5, 7};
        for (int i = 2; i <= 9; i++) {
            int n = (i % 2 == 0) ? i / 2 - 1 : i / 2;
            int base = pow10(n);
            for (int j = base; j < base * 10; j++) {
                int k = j, w = (i % 2 == 0) ? j : j / 10;
                while (w > 0) {
                    k = k * 10 + w % 10;
                    w /= 10;
                }
                if (k % 2 == 1)
                    ans.push_back(k);
            }
        }
        sort(ans.begin(), ans.end());
        return ans;
    }

    bool prime(int v) {
        if (v <= 2)
            return v == 2;
        int j = (int)sqrt((double)v);
        for (int i = 3; i <= j; i += 2) {
            if (v % i == 0)
                return false;
        }
        return true;
    }

public:
    int primePalindrome(int N) {
        if (N <= 2)
            return 2;
        vector<int> nums = generate();
        auto lower = lower_bound(nums.begin(), nums.end(), N);
        while (lower != nums.end() && !prime(*lower))
            lower++;
        return *lower;
    }
};
