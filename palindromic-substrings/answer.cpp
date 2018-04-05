#define N 1001
bool dp[N][N];

class Solution {
private:
    string s;
    int n;
    
    void init(const string& s) {
        this->s = s;
        n = s.size();
    }

    bool get(int i, int j) {
        if (j < i)
            return true;
        return dp[i][j - i + 1];
    }

    int solve() {
        for(int i = 0; i < n; i++) {
            dp[i][1] = true;
            for(int j = 2; i + j - 1 < n; j++)
                dp[i][j] = false;
        }
        
        for(int k = 2; k <= n; k++) {
            for(int i = 0; i + k - 1 < n; i++) {
                int j = i + k - 1;
                if (s[i] == s[j] && get(i + 1, j - 1))
                    dp[i][k] = true;
            }
        }
        int sum = 0;
        for(int k = 1; k <= n; k++) {
            for(int i = 0; i + k - 1 < n; i++)
                sum += dp[i][k] ? 1 : 0;
        }
        return sum;
    }

public:
    int countSubstrings(string s) {
        init(s);
        if (n <= 1)
            return n;
        return solve();
    }
};