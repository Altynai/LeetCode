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
    int maxWidthRamp(vector<int>& A) {
        vector<PII> pairs(A.size());
        FOR(i, 0, A.size()) pairs[i] = MP(A[i], i);
        sort(begin(pairs), end(pairs));

        set<int> seen;
        int ans = 0;
        FOR(i, 0, pairs.size()) {
            int where = pairs[i].second;
            if (!seen.empty())
                ans = max(ans, where - *seen.begin());
            seen.insert(where);
        }
        return ans;
    }
};
