#define i64 long long
#define VI vector<int>
#define PII pair<int, int>
#define MP(a, b) make_pair((a), (b))
#define FOR(i, s, t) for (int i = (s); i < (t); i++)
#define DFOR(i, s, t) for (int i = (s); i > (t); i--)
#define FILL(a, b) memset(a, b, sizeof(a))
#define PRINTVEC(v) std::copy(begin((v)), end((v)),std::ostream_iterator<int>(std::cout, " " )), cout << endl;
#define DEBUG(...) {printf("# ");printf(__VA_ARGS__);puts("");}

class Solution {
public:
    vector<int> beautifulArray(int N) {
        VI arr = {1};
        while (arr.size() < N) {
            int n = arr.size();
            arr.resize(n * 2);
            FOR(i, 0, n) arr[n + i] = arr[i] * 2;
            FOR(i, 0, n) arr[i] = arr[i] * 2 - 1;
        }
        VI ans;
        FOR(i, 0, arr.size()) {
            if (arr[i] <= N)
                ans.push_back(arr[i]);
        }
        return ans;
    }
};
