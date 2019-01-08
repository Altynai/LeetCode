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
private:
    VI listAll(int x, int bound) {
        if (x == 1)
            return {1};
        VI ans;
        int y = 1;
        while (y < bound) {
            ans.push_back(y);
            y *= x;
        }
        return ans;
    }

public:
    VI powerfulIntegers(int x, int y, int bound) {
        unordered_set<int> seen;
        VI xs = listAll(x, bound), ys = listAll(y, bound);

        FOR(i, 0, xs.size()) FOR(j, 0, ys.size()) {
            if (xs[i] + ys[j] <= bound)
                seen.insert(xs[i] + ys[j]);
        }
        return VI(begin(seen), end(seen));
    }
};
