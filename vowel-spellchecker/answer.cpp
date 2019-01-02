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
    string vowel(const string& s) {
        int n = s.size();
        char buf[n];
        FOR(i, 0, n) {
            buf[i] = s[i];
            if (s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u')
                buf[i] = '#';
        }
        return string(buf, buf + n);
    }

public:
    vector<string> spellchecker(vector<string>& wordlist, vector<string>& queries) {
        unordered_map<string, string> cache;
        unordered_set<string> orig;

        FOR(i, 0, wordlist.size()) {
            orig.insert(wordlist[i]);
            string word = wordlist[i];
            transform(word.begin(), word.end(), word.begin(), ::tolower);
            if (cache.find(word) == cache.end())
                cache[word] = wordlist[i];
            word = vowel(word);
            if (cache.find(word) == cache.end())
                cache[word] = wordlist[i];
        }

        int n = queries.size();
        vector<string> ans(n, "");
        FOR(i, 0, n) {
            string query = queries[i];
            auto j = orig.find(query);
            if (j != orig.end()) {
                ans[i] = *j;
                continue;
            }
            transform(query.begin(), query.end(), query.begin(), ::tolower);
            auto it = cache.find(query);
            if (it == cache.end())
                it = cache.find(vowel(query));
            if (it != cache.end())
                ans[i] = it->second;
        }
        return ans;
    }
};
