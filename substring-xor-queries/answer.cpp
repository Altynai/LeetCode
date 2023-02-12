using int64 = long long;
#define bit(n, i) (((n) >> (i)) & 1)

const int N = 32;

class Solution {
public:
  int length(int x) {
    if (x == 0)
      return 1;

    int res = 0;
    while (x > 0)
      res++, x >>= 1;
    return res;
  }

  vector<vector<int>> substringXorQueries(string s,
                                          vector<vector<int>> &queries) {
    int n = s.size();

    vector<map<int64, int>> c(N);
    for (int len = 1; len < N; len++) {
      int64 cur = 0;
      for (int i = 0; i < n; i++) {
        if (i >= len and bit(cur, len - 1))
          cur ^= (1LL << (len - 1));
        cur <<= 1;
        cur |= (s[i] - '0');
        if (c[len].find(cur) == c[len].end())
          c[len][cur] = i;
      }
    }

    vector<vector<int>> ans;
    for (auto q : queries) {
      int64 val = q[0] ^ q[1];
      int m = length(val);
      int l = -1, r = -1;

      auto it = c[m].find(val);
      if (it != c[m].end()) {
        r = it->second;
        l = r - m + 1;
      }
      ans.push_back({l, r});
    }
    return ans;
  }
};
