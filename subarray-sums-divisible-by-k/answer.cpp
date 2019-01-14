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
    int subarraysDivByK(vector<int>& A, int K) {
        int n = A.size(); 
        int ans = 0;
        VI sum(n + 1, 0);
        FOR(i, 1, n + 1)
            sum[i] = ((sum[i - 1] + A[i - 1]) % K + K) % K;

        unordered_map<int, int> cnt;
        FOR(i, 1, n + 1) {
            auto it = cnt.find(sum[i]);
            if (it != cnt.end())
                ans += it->second;
            if (sum[i] == 0)
                ans++;
            cnt[sum[i]]++;
        }
        return ans;
    }
};
