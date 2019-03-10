#define N 20003
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

void cmin(int& x, int y) {
    if (x == -1 || (y != -1 && y < x))
        x = y;
}

class Solution {
private:
    int f(vector<int>& A, vector<int>& B, int c, bool matchA) {
        int n = A.size(), sp = 0;
        FOR(i, 0, n) {
            int a = matchA ? A[i] : B[i];
            int b = matchA ? B[i] : A[i];
            if (a == c)
                continue;
            else if (b == c)
                sp++;
            else
                return -1;
        }
        return sp;
    }

public:
    int minDominoRotations(vector<int>& A, vector<int>& B) {
        int n = A.size(), ans = -1;
        FOR(c, 1, 7) {
            cmin(ans, f(A, B, c, true));
            cmin(ans, f(A, B, c, false));
        }
        return ans;
    }
};
