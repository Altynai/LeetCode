const int N = 26;

class Solution {
public:
  long long distinctNames(vector<string> &ideas) {
    int n = ideas.size();
    unordered_map<string, bitset<N>> m;
    for (int i = 0; i < n; i++) {
      string suf = ideas[i].substr(1);
      m[suf].set(ideas[i][0] - 'a');
    }

    // both not found = total - found in at least one set
    long long ans = 1LL * n * (n - 1);
    // aX, bY -> bX, aY
    // case 1: X == Y
    for (auto &[suf, inner] : m) {
      long long cnt = inner.count();
      ans -= cnt * (cnt - 1);
    }

    // X != Y
    vector<int> cnt(N, 0);
    vector<vector<int>> both(N, vector<int>(N, 0));
    for (auto &[suf, inner] : m) {
      for (int a = 0; a < N; a++) {
        if (inner.test(a)) {
          cnt[a]++;
          for (int b = 0; b < N; b++)
            if (a != b and inner.test(b))
              both[a][b]++;
        }
      }
    }

    // case 2: a == b
    for (int k = 0; k < N; k++)
      ans -= 1LL * cnt[k] * (cnt[k] - 1);

    // case 3: a != b, at least one is found
    for (int a = 0; a < N; a++) {
      for (auto &[suf, inner] : m)
        if (inner.test(a)) {
          // bX is found, we don't care about aY
          for (int b = 0; b < N; b++)
            if (a != b and inner.test(b)) {
              // # of suffix has b?
              ans -= cnt[b] - 1;
            }
          // bX is not found, aY and bY must exist
          for (int b = 0; b < N; b++)
            if (a != b and !inner.test(b)) {
              // # of boht has a and b?
              ans -= both[a][b];
            }
        }
    }
    return ans;
  }
};
