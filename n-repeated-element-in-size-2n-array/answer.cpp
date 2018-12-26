#define N 1
#define i64 long long
#define PII pair<int, int>
#define MP(a, b) make_pair((a), (b))
#define FOR(i, s, t) for (int i = (s); i < (t); i++)
#define DFOR(i, s, t) for (int i = (s); i > (t); i--)
#define FILL(a, b) memset(a, b, sizeof(a))
#define PRINTVEC(v) std::copy(begin((v)), end((v)),std::ostream_iterator<int>(std::cout, " " )), cout << endl;

const i64 MOD = 1000000000 + 7;

class Solution {
public:
    int repeatedNTimes(vector<int>& A) {
        int mx = *max_element(begin(A), end(A));
        int cnt[mx + 1]; FILL(cnt, 0);
        int n = A.size() / 2;
        FOR(i, 0, A.size())
            if (++cnt[A[i]] == n)
                return A[i];
        return 0;
    }
};
