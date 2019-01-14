#define N 1
#define i64 long long
#define VI vector<int>
#define PII pair<int, int>
#define MP(a, b) make_pair((a), (b))
#define FOR(i, s, t) for (int i = (s); i < (t); i++)
#define DFOR(i, s, t) for (int i = (s); i > (t); i--)
#define FILL(a, b) memset(a, b, sizeof(a))
#define PRINTVEC(v) std::copy(begin((v)), end((v)),std::ostream_iterator<int>(std::cout, " " )), cout << endl;
#define DEBUG(...) {printf("# ");printf(__VA_ARGS__);puts("");}
const i64 MOD = 1000000000 + 7;

class Solution {
public:
    int oddEvenJumps(vector<int>& A) {
        int n = A.size();
        VI odd(n, -1), even(n, -1);
        
        map<int, int> seen;
        seen[A[n - 1]] = n - 1;
        DFOR(i, n - 2, -1) {
            auto it = seen.lower_bound(A[i]);
            if (it != seen.end())
                odd[i] = it->second;
            if (it != seen.end() && it->first == A[i])
                even[i] = it->second;
            else if (it != seen.begin()) {
                --it;
                even[i] = it->second;
            }
            seen[A[i]] = i;
        }
        
        bool dp[n][2];
        FILL(dp, 0);
        dp[n - 1][0] = dp[n - 1][1] = true;

        DFOR(i, n - 2, -1) {
            if (odd[i] != -1 && dp[odd[i]][0])
                dp[i][1] = true;
            if (even[i] != -1 && dp[even[i]][1])
                dp[i][0] = true;
        }
        
        int ans = 0;
        FOR(i, 0, n) {
            if (dp[i][1])
                ans++;
        }
        return ans;
    }
};
