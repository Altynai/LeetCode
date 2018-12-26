#define N 1
#define i64 long long
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
    unordered_map<int, int> cache;

    int dfs(int x, int target) {
        auto it = cache.find(target);
        if (it != cache.end())
            return it->second;

        if (x > target) 
            return cache[target] = min(target * 2, (x - target) * 2 + 1);

        i64 now = 1;
        int cnt = 0;
        // x < target
        while (now * x < (i64)target) {
            now *= x;
            cnt++;
        }

        int ans1 = cnt + dfs(x, target - now);
        cache[target] = ans1;

        int ans2 = cnt + 1 + dfs(x, now * x - target);
        return cache[target] = min(ans1, ans2);
    }

public:
    int leastOpsExpressTarget(int x, int target) {
        cache.clear();
        cache[x] = 1;
        cache[0] = 0;
        return dfs(x, target) - 1;
    }
};
