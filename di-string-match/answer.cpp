#define i64 long long
#define PII pair<int, int>
#define MP(a, b) make_pair((a), (b))
#define FOR(i, s, t) for (int i = (s); i < (t); i++)
#define FILL(a, b) memset(a, b, sizeof(a))
#define PRINTVEC(v) std::copy((v).begin(),(v).end(),std::ostream_iterator<int>(std::cout, " " ))

class Solution {
private:
    vector<int> incr(const string& S) {
        int n = S.size();
        vector<int> ans(n + 1);
        FOR(i, 0, n + 1)
            ans[i] = i;

        for (int i = 0; i < n; i++) {
            if (S[i] == 'I')
                continue;
            int j = i;
            while (j < n && S[j] == 'D')
                j++;
            std::reverse(begin(ans) + i, begin(ans) + j + 1);
            i = j;
        }
        return ans;
    }

    vector<int> decr(const string& S) {
        int n = S.size();
        vector<int> ans(n + 1);
        FOR(i, 0, n + 1)
            ans[i] = i;
        reverse(begin(ans), end(ans));

        for (int i = 0; i < n; i++) {
            if (S[i] == 'D')
                continue;
            int j = i;
            while (j < n && S[j] == 'I')
                j++;
            std::reverse(begin(ans) + i, begin(ans) + j + 1);
            i = j;
        }
        return ans;
    }

public:
    vector<int> diStringMatch(string S) {
        return (S[0] == 'I') ? incr(S) : decr(S);
    }
};
