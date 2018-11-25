#define N 1001
#define i64 long long
#define PII pair<int, int>
#define MP(a, b) make_pair((a), (b))
#define FOR(i, s, t) for (int i = (s); i < (t); i++)
#define DFOR(i, s, t) for (int i = (s); i > (t); i--)
#define FILL(a, b) memset(a, b, sizeof(a))
#define PRINTVEC(v) std::copy(begin((v)), end((v)),std::ostream_iterator<int>(std::cout, " " )), cout << endl;

int fa[N];

int find(int x) {
    int r = x;
    while (fa[r] != r)
        r = fa[r];
    int i = x, j;
    while (i != r) {
        j = fa[i];
        fa[i] = r;
        i = j;
    }
    return r;
}

class Solution {
public:
    int removeStones(vector<vector<int>>& stones) {
        int n = stones.size();
        FOR(i, 0, n) fa[i] = i;
        
        FOR(i, 0, n) FOR(j, 0, n) {
            if (i == j)
                continue;
            int x1 = stones[i][0], y1 = stones[i][1];
            int x2 = stones[j][0], y2 = stones[j][1];
            if (x1 == x2 || y1 == y2) {
                int ri = find(i), rj = find(j);
                fa[ri] = rj;
            }
        }
        
        map<int, int> cnt;
        FOR(i, 0, n) {
            int r = find(i);
            ++cnt[r];
        }
        int ans = 0;
        for (auto it = begin(cnt); it != end(cnt); it++)
            ans += (it->second) - 1;
        return ans;
    }
};
