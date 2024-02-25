template <typename T>
using min_priority_queue = priority_queue<T, vector<T>, greater<T>>;

using int64 = long long;

class Solution {
public:
  int earliestSecondToMarkIndices(vector<int> &a, vector<int> &b) {
    int n = a.size(), m = b.size(), ans = -1;
    for (int &index : b)
      index--;

    auto Test = [&](int k) -> int {
      vector<int> c = a;

      vector<int> first_seen_at(n, -1);
      vector<bool> is_first_seen(k + 1, 0);
      for (int i = 0; i <= k; i++) {
        int j = b[i];
        if (a[j] > 0 and first_seen_at[j] == -1) {
          first_seen_at[j] = i;
          is_first_seen[i] = 1;
        }
      }

      // good spot: we can either use it to decrease or mark
      // bad spot: we must use it to reset to zero
      min_priority_queue<pair<int, int>> que;
      int64 decr_or_mark = 0;
      for (int i = k; i >= 0; i--) {
        int j = b[i];
        if (is_first_seen[i]) {
          que.push({c[j], i});
          // indirect good spot
          if (decr_or_mark == 0) {
            decr_or_mark++;
            que.pop();
          } else {
            // bad spot
            decr_or_mark--;
          }
        }
        // direct good spot
        else {
          decr_or_mark++;
        }
      }

      // bad spots have been considered as set to zero and marked
      // the reset should also be marked
      decr_or_mark -= n - que.size();

      while (!que.empty()) {
        int j = b[que.top().second];
        c[j] = 0;
        que.pop();
      }

      for (int x : c) {
        if (x > 0)
          decr_or_mark -= x;
      }
      return decr_or_mark >= 0;
    };

    for (int l = 0, r = m - 1; l <= r;) {
      int mid = (l + r) / 2;
      if (Test(mid))
        ans = mid + 1, r = mid - 1;
      else
        l = mid + 1;
    }
    return ans;
  }
};
