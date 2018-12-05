#define N 100005
#define i64 long long
#define PII pair<int, int>
#define MP(a, b) make_pair((a), (b))
#define FOR(i, s, t) for (int i = (s); i < (t); i++)
#define DFOR(i, s, t) for (int i = (s); i > (t); i--)
#define FILL(a, b) memset(a, b, sizeof(a))
#define PRINTVEC(v) std::copy(begin((v)), end((v)),std::ostream_iterator<int>(std::cout, " " )), cout << endl;

const i64 MOD = 1000000000 + 7;

class DSU {
public:
    vector<int> f;

    DSU(int n) : f(n) {
        FOR(i, 0, n) f[i] = i;
    }
    
    int find(int x) {
        int r = x;
        while (f[r] != r)
            r = f[r];
        int i = x, j = x;
        while (i != r) {
            j = f[i];
            f[i] = r;
            i = j;
        }
        return r;
    }
    
    void join(int x, int y) {
        int ra = find(x);
        int rb = find(y);
        f[max(ra, rb)] = min(ra, rb);
    }
};

class Solution {
public:
    int largestComponentSize(vector<int>& A) {
        int mx = *max_element(begin(A), end(A));
        DSU dsu(mx + 1);

        FOR(i, 0, A.size()) {
            int k = (int)sqrt(A[i]) + 1;
            FOR(j, 2, k) {
                if (A[i] % j == 0) {
                    dsu.join(A[i], j);
                    dsu.join(A[i], A[i] / j);
                }
            }
        }
        
        int ans = 0;
        unordered_map<int, int> cnt;
        FOR(i, 0, A.size())
            ans = max(ans, ++cnt[dsu.find(A[i])]);

        return ans;
    }
};
