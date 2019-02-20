#define N 1
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
    int minKBitFlips(vector<int>& A, int K) {
        int n = A.size(), ans = 0;
        deque<int> flips;
        FOR(i, 0, n - K + 1) {
            while (!flips.empty() && flips.front() < i - K + 1)
                flips.pop_front();
            if (flips.size() % 2 == 1)
                A[i] ^= 1;
            if (A[i] == 0) {
                flips.push_back(i);
                ans++;
            }
        }
        FOR(i, n - K + 1, n) {
            while (!flips.empty() && flips.front() < i - K + 1)
                flips.pop_front();
            if (flips.size() % 2 == 1)
                A[i] ^= 1;
            if (A[i] == 0)
                return -1;
        }
        return ans;
    }
};
