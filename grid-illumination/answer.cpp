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
public:
    vector<int> gridIllumination(int N, vector<vector<int>>& lamps, vector<vector<int>>& queries) {
        int n = lamps.size(), m = queries.size();
        VI ans(m, 0);
        
        set<PII> seen;
        unordered_map<int, int> r, c, pb, nb;
        FOR(i, 0, n) {
            int x = lamps[i][0], y = lamps[i][1];
            seen.insert(MP(x, y));
            r[x]++;
            c[y]++;
            pb[y - x]++;
            nb[y + x]++;
        }
        
        FOR(i, 0, m) {
            int x = queries[i][0], y = queries[i][1];
            if (r.find(x) != r.end() || c.find(y) != c.end() || pb.find(y - x) != pb.end() || nb.find(y + x) != nb.end())
                ans[i] = 1;

            FOR(j, -1, 2) FOR(k, -1, 2) {
                int nx = x + j, ny = y + k;
                if (seen.find(MP(nx, ny)) != seen.end()) {
                    if (--r[nx] == 0) r.erase(nx);
                    if (--c[ny] == 0) c.erase(ny);
                    if (--pb[ny - nx] == 0) pb.erase(ny - nx);
                    if (--nb[ny + nx] == 0) nb.erase(ny + nx);
                }
            }
        }
        return ans;
    }
};
