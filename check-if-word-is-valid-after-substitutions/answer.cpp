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
    bool isValid(string S) {
        int n = S.size(), top = 0;
        char stk[n];

        FOR(i, 0, n) {
            stk[top++] = S[i];
            if (top >= 3 && stk[top - 3] == 'a' && stk[top - 2] == 'b' && stk[top - 1] == 'c')
                top -= 3;
        }

        return top == 0;
    }
};
