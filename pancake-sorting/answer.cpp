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
    VI pancakeSort(vector<int>& A) {
        VI ans;
        DFOR(i, A.size() - 1, -1) {
            if (A[i] == i + 1)
                continue;
            int j = i - 1;
            while (j >= 0 && A[j] != i + 1)
                j--;
            if (j >= 0) {
                reverse(begin(A), begin(A) + j + 1);
                ans.push_back(j + 1);
                reverse(begin(A), begin(A) + i + 1);
                ans.push_back(i + 1);
            }
        }
        return ans;
    }
};
