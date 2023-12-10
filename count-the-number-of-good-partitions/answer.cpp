const int MOD = 1e9 + 7;

class Solution {
public:
  int numberOfGoodPartitions(vector<int> &a) {
    int n = a.size();

    vector<int> psum(n + 1, 0);
    unordered_map<int, int> l, r;
    for (int i = 1; i <= n; i++) {
      int x = a[i - 1];
      if (l.count(x) == 0)
        l[x] = i;
      r[x] = i;
    }

    int uniq = l.size();
    for (auto [x, lpos] : l) {
      int rpos = r[x];
      psum[0] += 1;
      if (lpos < rpos) {
        psum[lpos + 1] -= 1;
        if (rpos + 1 <= n)
          psum[rpos + 1] += 1;
      }
    }

    int ans = 1;
    for (int i = 1; i <= n; i++) {
      psum[i] += psum[i - 1];
      if (i > 1 and psum[i] == uniq)
        ans = ans * 2 % MOD;
    }
    return ans;
  }
};
