const int N = 26;

class Solution {
public:
  vector<bool> canMakePalindromeQueries(string s,
                                        vector<vector<int>> &queries) {
    int n = s.size();
    int m = n / 2;

    string t = s.substr(m);
    reverse(t.begin(), t.end());
    s = s.substr(0, m);

    vector<int> matched(m, 0);
    for (int i = 0; i < m; i++) {
      int x = int(s[i] == t[i]);
      matched[i] = (i > 0 ? matched[i - 1] : 0) + x;
    }

    vector<vector<int>> cnts(m, vector<int>(N, 0));
    vector<vector<int>> cntt(m, vector<int>(N, 0));
    for (int i = 0; i < m; i++) {
      if (i > 0) {
        cnts[i] = cnts[i - 1];
        cntt[i] = cntt[i - 1];
      }
      cnts[i][s[i] - 'a']++;
      cntt[i][t[i] - 'a']++;
    }

    auto IsRangeMatched = [&](int l, int r) -> bool {
      if (l > r)
        return 1;
      if (l == 0)
        return matched[r] == r + 1;
      return matched[r] - matched[l - 1] == r - l + 1;
    };

    auto IsRangeCountSame = [&](int l, int r) -> bool {
      if (l > r)
        return 1;
      for (int i = 0; i < N; i++) {
        int x = (l == 0 ? cnts[r][i] : cnts[r][i] - cnts[l - 1][i]);
        int y = (l == 0 ? cntt[r][i] : cntt[r][i] - cntt[l - 1][i]);
        if (x != y)
          return 0;
      }
      return 1;
    };

    auto GetRangeCount = [&](const vector<vector<int>> &c, int l,
                             int r) -> vector<int> {
      vector<int> res(N, 0);
      for (int i = 0; i < N; i++) {
        res[i] = (l == 0 ? c[r][i] : c[r][i] - c[l - 1][i]);
      }
      return res;
    };

    auto Get = [&](int a, int b, int c, int d) -> bool {
      // not overlapped
      // s: .... [a ... b] ............
      // t: .... ............. [c .. d]
      if (b < c) {
        return IsRangeMatched(0, a - 1) and IsRangeCountSame(a, b) and
               IsRangeMatched(b + 1, c - 1) and IsRangeCountSame(c, d) and
               IsRangeMatched(d + 1, m - 1);
      }

      // not overlapped
      // s: .... ............. [a .. b]
      // t: .... [c ... d] ............
      if (d < a) {
        return IsRangeMatched(0, c - 1) and IsRangeCountSame(c, d) and
               IsRangeMatched(d + 1, a - 1) and IsRangeCountSame(a, b) and
               IsRangeMatched(b + 1, m - 1);
      }

      // overlapped
      // s: .... ....[a .. b] .........
      // t: .... [c ... d] ............
      if (c <= a and a <= d and d <= b) {
        vector<int> ct = GetRangeCount(cntt, c, d);
        for (int i = c; i < a; i++) {
          if (--ct[s[i] - 'a'] < 0)
            return 0;
        }
        vector<int> cs = GetRangeCount(cnts, a, b);
        for (int i = d + 1; i <= b; i++) {
          if (--cs[t[i] - 'a'] < 0)
            return 0;
        }
        return IsRangeMatched(0, c - 1) and IsRangeMatched(b + 1, m - 1) and
               cs == ct;
      }

      // overlapped
      // s: .... [a ... b] ............
      // t: .... ....[c .. d] .........
      if (a <= c and c <= b and b <= d) {
        vector<int> cs = GetRangeCount(cnts, a, b);
        for (int i = a; i < c; i++) {
          if (--cs[t[i] - 'a'] < 0)
            return 0;
        }
        vector<int> ct = GetRangeCount(cntt, c, d);
        for (int i = b + 1; i <= d; i++) {
          if (--ct[s[i] - 'a'] < 0)
            return 0;
        }
        return IsRangeMatched(0, a - 1) and IsRangeMatched(d + 1, m - 1) and
               cs == ct;
      }

      // overlapped
      // s: .... [a ......... b] ......
      // t: .... ....[c .. d] .........
      if (a <= c and d <= b) {
        vector<int> cs = GetRangeCount(cnts, a, b);
        for (int i = a; i < c; i++) {
          if (--cs[t[i] - 'a'] < 0)
            return 0;
        }
        for (int i = d + 1; i <= b; i++) {
          if (--cs[t[i] - 'a'] < 0)
            return 0;
        }

        vector<int> ct = GetRangeCount(cntt, c, d);
        return IsRangeMatched(0, a - 1) and IsRangeMatched(b + 1, m - 1) and
               cs == ct;
      }

      // overlapped
      // s: .... ....[a .. b] .........
      // t: .... [c ......... d] ......
      if (c <= a and b <= d) {
        vector<int> ct = GetRangeCount(cntt, c, d);
        for (int i = c; i < a; i++) {
          if (--ct[s[i] - 'a'] < 0)
            return 0;
        }
        for (int i = b + 1; i <= d; i++) {
          if (--ct[s[i] - 'a'] < 0)
            return 0;
        }

        vector<int> cs = GetRangeCount(cnts, a, b);
        return IsRangeMatched(0, c - 1) and IsRangeMatched(d + 1, m - 1) and
               cs == ct;
      }
      // dead code
      return 0;
    };

    int q = queries.size();
    vector<bool> ans(q);
    for (int i = 0; i < q; i++) {
      int a = queries[i][0], b = queries[i][1];
      int c = n - 1 - queries[i][3], d = n - 1 - queries[i][2];
      ans[i] = Get(a, b, c, d);
    }
    return ans;
  }
};
