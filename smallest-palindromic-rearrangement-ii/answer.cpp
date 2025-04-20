using int64 = long long;

// NOTE: good performance with pre-calculation
template <class T> struct Comb {
  static const int N = 5000 + 1;
  static const int M = N;

  T C[N][M];

  void init(int n, int m, int k) {
    C[0][0] = 1;
    for (int i = 1; i <= n; i++) {
      C[i][0] = 1;
      for (int j = 1; j <= m; j++) {
        C[i][j] = C[i - 1][j - 1] + C[i - 1][j];
        // larger number is marked as k + 1
        C[i][j] = min(C[i][j], k + 1);
      }
    }
  }

  T choose(int n, int r) {
    if (n < r)
      return 0;
    if (r == 0)
      return 1;
    return C[n][r];
  }
};

Comb<int> comb;

class Solution {
public:
  string smallestPalindrome(string s, int k) {
    const int MAX = 26;

    int n = s.size();
    vector<int> cnt(MAX, 0);
    for (char ch : s)
      cnt[ch - 'a']++;

    int odd = -1;
    for (int i = 0; i < MAX; i++) {
      if (cnt[i] & 1) {
        odd = i;
        cnt[i]--;
        break;
      }
    }

    for (int i = 0; i < MAX; i++)
      cnt[i] /= 2;
    int m = accumulate(cnt.begin(), cnt.end(), 0);

    comb.init(m, m, k);

    string res;
    for (int i = 0; i < m; i++) {
      int best = -1;
      int64 counted = 0;

      for (int j = 0; j < MAX; j++) {
        if (cnt[j] == 0)
          continue;

        cnt[j]--;
        int64 ways = 1;
        int spots = m - i - 1;
        for (int op = 0; op < MAX; op++) {
          if (cnt[op] == 0)
            continue;
          ways *= comb.choose(spots, cnt[op]);
          spots -= cnt[op];
          ways = min(ways, 1LL * (k + 1));
        }
        cnt[j]++;

        if (counted + ways >= k) {
          best = j;
          k -= counted;
          break;
        } else {
          counted += ways;
        }
      }

      if (best == -1)
        return "";
      res.push_back('a' + best);
      cnt[best]--;
    }

    if (odd != -1)
      res.push_back('a' + odd);
    for (int i = m - 1; i >= 0; i--)
      res.push_back(res[i]);
    return res;
  }
};
