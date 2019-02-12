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
private:
    int count(vector<int>& A, int K) {
        int n = A.size(), l = 0, dis = 0, ans = 0;
        unordered_map<int, int> cnt;
        FOR(i, 0, n) {
            if (++cnt[A[i]] == 1)
                dis++;
            while (dis > K) {
                if (--cnt[A[l++]] == 0)
                    dis--;
            }
            ans += i - l + 1;
        }
        return ans;
    }

public:
    int subarraysWithKDistinct(vector<int>& A, int K) {
        return count(A, K) - count(A, K - 1);
    }
};
