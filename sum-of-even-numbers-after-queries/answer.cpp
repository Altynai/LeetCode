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
    vector<int> sumEvenAfterQueries(vector<int>& A, vector<vector<int>>& queries) {
        VI ans;
        int sum = 0, n = A.size();
        FOR(i, 0, n) {
            if (A[i] % 2 == 0)
                sum += A[i];
        }
        
        FOR(i, 0, queries.size()) {
            int val = queries[i][0], j = queries[i][1];
            bool before = bool(A[j] % 2 == 0);
            A[j] += val;
            bool after = bool(A[j] % 2 == 0);
            if (before && after)
                sum += val;
            else if (!before && after)
                sum += A[j];
            else if (before && !after)
                sum -= (A[j] - val);
            ans.push_back(sum);
        }
        return ans;
    }
};
