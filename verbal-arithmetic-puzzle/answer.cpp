#define N 10
#define i64 long long
#define VI vector<int>
#define VS vector<string>
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
    bool non_zero_chars[26];
    int uniq[N];
    int factor[N];
    bool used[N];
    int uc;

    void init(VS& words, string result) {
        FILL(non_zero_chars, 0);

        set<char> seen;
        unordered_map<char, int> multiplier;
        FOR(i, 0, words.size()) {
            non_zero_chars[words[i][0] - 'A'] = true;
            seen.insert(words[i].begin(), words[i].end());
            int pow = 1, n = words[i].size();
            FOR(j, 0, n) {
                multiplier[words[i][n - 1 - j]] += pow;
                pow *= 10;
            }
        }

        non_zero_chars[result[0] - 'A'] = true;
        seen.insert(result.begin(), result.end());
        int pow = 1, n = result.size();
        FOR(j, 0, n) {
            multiplier[result[n - 1 - j]] -= pow;
            pow *= 10;
        }

        uc = 0;
        for (auto const& item : multiplier) {
            if (item.second != 0) {
                uniq[uc] = item.first - 'A';
                factor[uc++] = item.second;
            }
        }
    }

    bool dfs(int i, int sum) {
        if (i == uc)
            return sum == 0;
        FOR(j, 0, 10) {
            if (used[j] || (j == 0 && non_zero_chars[uniq[i]]))
                continue;
            used[j] = true;
            if (dfs(i + 1, sum + j * factor[i]))
                return true;
            used[j] = false;
        }
        return false;
    }

public:
    bool isSolvable(vector<string>& words, string result) {
        init(words, result);
        FILL(used, 0);
        return dfs(0, 0);
    }
};
