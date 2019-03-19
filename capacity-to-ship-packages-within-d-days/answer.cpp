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
    int shipWithinDays(vector<int>& weights, int D) {
        int l = *max_element(begin(weights), end(weights)), r = 0x3f3f3f3f, mid, ans = -1;
        while (l <= r) {
            mid = (l + r) >> 1;
            int day = 1, sum = 0;
            FOR(i, 0, weights.size()) {
                sum += weights[i];
                if (sum > mid) {
                    day++;
                    sum = weights[i];
                }
            }
            if (day <= D) {
                ans = mid;
                r = mid - 1;
            } else
                l = mid + 1;
        }
        return ans;
    }
};
