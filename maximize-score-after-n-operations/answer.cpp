// functions
template <class T>
inline bool umin(T &a, const T b) { return b < a ? a = b, 1 : 0; }
template <class T>
inline bool umax(T &a, const T b) { return a < b ? a = b, 1 : 0; }
// =====================================================================================================================


class Solution {
public:
    int maxScore(vector<int>& nums) {
        int n = nums.size();
        vector<int> g(1 << n, 0);
        vector<int> dp(1 << n, 0);
        
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n;j ++) {
                int state = (1 << i) | (1 << j);
                dp[state] = g[state] = gcd(nums[i], nums[j]);
            }
        }
        
        for (int i = 2;i <= n/ 2;i++) {
            vector<int> ndp(1 << n, 0);
            for(int j = 0; j < (1 << n);j++) {
                if (dp[j] == 0)
                    continue;
                int mask = ((1 << n) - 1) ^ j;
                for (int k = mask; k > 0; k = mask & (k-1)) {
                    if (g[k]) {
                        umax(ndp[j | k], dp[j] + i * g[k]);
                    }
                }
            }
            dp = ndp;
        }
        return dp[(1 << n) - 1];
    }
};
