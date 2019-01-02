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
private:
    unordered_set<int> ans;
    int n, k;

    void dfs(int val, int cnt) {
        if (cnt == n) {
            ans.insert(val);
            return;
        }
        int last = val % 10;
        if (last + k < 10)
            dfs(val * 10 + last + k, cnt + 1);
        if (last - k >= 0)
            dfs(val * 10 + last - k, cnt + 1);
    }

public:
    vector<int> numsSameConsecDiff(int N, int K) {
        ans.clear();
        n = N;
        k = K;

        FOR(i, 1, 10) dfs(i, 1);
        if (N == 1)
            ans.insert(0);
        return vector<int>(begin(ans), end(ans));
    }
};
