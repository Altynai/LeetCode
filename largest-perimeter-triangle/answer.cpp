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
    int largestPerimeter(vector<int>& A) {
        sort(begin(A), end(A));
        int mx = A[0] + A[1], ans = 0;
        FOR(i, 2, A.size()) {
            if (mx > A[i])
                ans = max(ans, mx + A[i]);
            mx = max(mx, A[i] + A[i - 1]);
        }
        return ans;
    }
};
