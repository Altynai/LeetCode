#define N 1
#define i64 long long
#define PII pair<int, int>
#define MP(a, b) make_pair((a), (b))
#define FOR(i, s, t) for (int i = (s); i < (t); i++)
#define DFOR(i, s, t) for (int i = (s); i > (t); i--)
#define FILL(a, b) memset(a, b, sizeof(a))
#define PRINTVEC(v) std::copy(begin((v)), end((v)),std::ostream_iterator<int>(std::cout, " " )), cout << endl;

class Solution {
public:
    int minDeletionSize(vector<string>& A) {
        int n = A.size(), m = A[0].size();
        unordered_set<int> seen;

        FOR(j, 0, m) FOR(i, 1, n) {
            bool same = true;
            FOR(k, 0, j) {
                if (seen.find(k) == seen.end() && A[i - 1][k] < A[i][k]) {
                    same = false;
                    break;
                }
            }
            if (same && A[i - 1][j] > A[i][j]) {
                seen.insert(j);
                break;
            }
        }

        return seen.size();
    }
};
