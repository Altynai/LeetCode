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
    vector<int> sortedSquares(vector<int>& A) {
        VI ans;
        int r = lower_bound(begin(A), end(A), 0) - begin(A);
        int l = r - 1, n = A.size();
        while (l >= 0 || r < n) {
            if (l < 0 || (r < n && abs(A[r]) <= abs(A[l])))
                ans.push_back(A[r] * A[r++]);
            else
                ans.push_back(A[l] * A[l--]);
        }
        return ans;
    }
};
