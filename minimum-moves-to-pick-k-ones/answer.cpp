using int64 = long long;

class Solution {
public:
  long long minimumMoves(vector<int> &a, int k, int maxChanges) {
    if (count(a.begin(), a.end(), 1) == 0)
      return k * 2;

    int n = a.size();
    vector<int> sum(n);
    vector<int64> total(n);
    for (int i = 0; i < n; i++) {
      sum[i] = (i == 0 ? 0 : sum[i - 1]) + a[i];
      total[i] = (i == 0 ? 0 : total[i - 1]) + (a[i] > 0 ? i : 0);
    }

    auto GetSum = [&](int l, int r) -> int {
      return l == 0 ? sum[r] : sum[r] - sum[l - 1];
    };

    auto GetTotal = [&](int l, int r) -> int64 {
      return l == 0 ? total[r] : total[r] - total[l - 1];
    };

    int64 ans = -1;
    for (int i = 0; i < n; i++) {
      int64 moves = 0;
      int p = k, had = 0;

      // check self
      if (a[i] == 1)
        p -= 1, had++;

      // check neighbors
      if (p > 0 and i > 0 and a[i - 1] == 1)
        p -= 1, moves++, had++;
      if (p > 0 and i + 1 < n and a[i + 1] == 1)
        p -= 1, moves++, had++;

      // use up the maxChanges
      if (p > 0) {
        int d = min(p, maxChanges);
        moves += d * 2;
        p -= d;
      }

      // use i as the center pick nearest p + had points where a[j] = 1
      if (p > 0) {
        int need = p + had;

        int len = -1;
        for (int l = 1, r = n; l <= r;) {
          int mid = (l + r) / 2;
          int x = max(0, i - mid + 1), y = min(n - 1, i + mid - 1);
          if (GetSum(x, y) >= need)
            len = mid, r = mid - 1;
          else
            l = mid + 1;
        }

        int L = max(0, i - len + 1), R = min(n - 1, i + len - 1);

        // edge case: both endpoints are 1, we need to remove one of them
        if (GetSum(L, R) == need + 1)
          L++;
        assert(GetSum(L, R) == need);

        if (L <= i - 2) {
          int count = GetSum(L, i - 2);
          int64 res = GetTotal(L, i - 2);
          moves += 1LL * i * count - res;
        }
        if (R >= i + 2) {
          int count = GetSum(i + 2, R);
          int64 res = GetTotal(i + 2, R);
          moves += res - 1LL * i * count;
        }
      }

      if (ans == -1 or moves < ans)
        ans = moves;
    }
    return ans;
  }
};
