class Solution {
public:
  int maxTaskAssign(vector<int> &a, vector<int> &b, int pills, int strength) {
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());

    int n = a.size(), m = b.size(), ans = 0;
    for (int l = 1, r = min(n, m); l <= r;) {
      int k = (l + r) >> 1;

      map<int, int> worker;
      for (int i = max(0, m - 1 - k - pills); i < m; i++)
        worker[b[i]]++;

      int p = pills;
      bool ok = true;
      for (int i = k - 1; ok && i >= 0; i--) {
        // worker >= a[i]
        auto it = worker.lower_bound(a[i]);
        // worker + strength >= a[i]
        if (it == worker.end() && p--)
          it = worker.lower_bound(a[i] - strength);

        if (it != worker.end()) {
          if (--(it->second) == 0)
            worker.erase(it);
        } else
          ok = false;
      }

      if (ok)
        ans = k, l = k + 1;
      else
        r = k - 1;
    }
    return ans;
  }
};
