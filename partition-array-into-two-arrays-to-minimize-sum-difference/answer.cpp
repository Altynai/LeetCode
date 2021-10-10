#define bit(n, i) (((n) >> (i)) & 1)

class Solution {
public:
  int minimumDifference(vector<int> &a) {
    int m = a.size();
    int n = m / 2;
    int sum = accumulate(a.begin(), a.end(), 0);
    int half = sum / 2;

    vector<vector<int>> op1(n + 1), op2(n + 1);
    for (int mask = 0; mask < (1 << n); mask++) {
      int s1 = 0, s2 = 0, c = 0;
      for (int i = 0; i < n; i++) {
        if (bit(mask, i)) {
          s1 += a[i];
          s2 += a[i + n];
          c += 1;
        }
      }
      op1[c].push_back(s1);
      op2[c].push_back(s2);
    }
    for (int i = 0; i <= n; i++) {
      sort(op2[i].begin(), op2[i].end());
      op2[i].resize(unique(op2[i].begin(), op2[i].end()) - op2[i].begin());
    }

    int ans = INT_MAX;
    for (int i = 0; i <= n; i++) {
      // pick i from op1, pick n - i from op2
      for (int x : op1[i]) {
        // x + y <= half -> y < half - x + 1
        auto it =
            lower_bound(op2[n - i].begin(), op2[n - i].end(), half - x + 1);
        if (it != op2[n - i].begin()) {
          it = prev(it);
          int sum1 = x + *it;
          int sum2 = sum - sum1;
          ans = min(ans, abs(sum1 - sum2));
        }
      }
    }
    return ans;
  }
};
