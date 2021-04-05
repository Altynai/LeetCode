class Solution {
public:
  int minAbsoluteSumDiff(vector<int> &a, vector<int> &b) {
    int n = a.size();
    set<int> seen(a.begin(), a.end());

    int MOD = 1e9 + 7;
    int reduce = 0;
    for (int i = 0; i < n; i++) {
      if (a[i] == b[i])
        continue;

      seen.erase(a[i]);
      int diff = abs(a[i] - b[i]);
      // x > b[i]
      auto it = seen.upper_bound(b[i]);
      if (it != seen.end()) {
        int diff2 = abs(*it - b[i]);
        if (diff2 < diff)
          reduce = max(reduce, diff - diff2);
      }
      // x <= b[i]
      it = seen.upper_bound(b[i]);
      if (it != seen.begin()) {
        it = prev(it);
        int diff2 = abs(*it - b[i]);
        if (diff2 < diff)
          reduce = max(reduce, diff - diff2);
      }

      seen.insert(a[i]);
    }

    int ans = MOD - reduce;
    for (int i = 0; i < n; i++)
      ans = (ans + abs(a[i] - b[i])) % MOD;
    return ans;
  }
};
