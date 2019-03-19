#define i64 long long
#define VI vector<int>
#define VVI vector<vector<int>>
#define PII pair<int, int>
#define SZ(a) (a).size()
#define MP(a, b) make_pair((a), (b))
#define FOR(i, s, t) for (int i = (s); i < (t); i++)
#define DFOR(i, s, t) for (int i = (s); i > (t); i--)
#define FILL(a, b) memset(a, b, sizeof(a))
#define PRINTVEC(v) std::copy(begin((v)), end((v)),std::ostream_iterator<int>(std::cout, " " )), cout << endl;
#define DEBUG(...) {printf("# ");printf(__VA_ARGS__);puts("");}
const i64 MOD = 1000000000 + 7;

class Solution {
private:
    int n, ans;

    void dfs(i64 m, int mask) {
        if (m > n)
            return;
        ans++;
        FOR(i, 0, 10) {
            if (mask & (1 << i))
                continue;
            if (i == 0 && m == 0)
                continue;
            dfs(m * 10 + i, mask | (1 << i));
        }
    }

public:
    int numDupDigitsAtMostN(int N) {
        n = N;
        ans = 0;
        dfs(0LL, 0);
        return N + 1 - ans;
    }
};
