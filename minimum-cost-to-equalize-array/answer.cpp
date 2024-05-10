const int MOD = 1e9 + 7;

using int64 = long long;

class Solution {
public:
  int minCostToEqualizeArray(vector<int> &a, int cost1, int cost2) {
    int n = a.size();
    int maxv = *max_element(a.begin(), a.end());
    int minv = *min_element(a.begin(), a.end());

    int64 sum = 0;
    for (int i = 0; i < n; i++)
      sum += maxv - a[i];

    // we can only use cost1
    if (cost1 * 2 <= cost2 or n <= 2) {
      return sum * cost1 % MOD;
    }

    // cost1 is expensive, we try to use cost2 as much as we can
    int64 ans = LLONG_MAX;
    for (int target = maxv; target <= maxv * 2; target++) {
      int64 largest = target - minv, total = 0;
      if (largest > sum - largest) {
        // decrease at most (sum - largest) times with operation 2
        total += (sum - largest) * cost2;
        total += (sum - (sum - largest) * 2) * cost1;
      } else {
        total += sum / 2 * cost2;
        if (sum & 1)
          total += cost1;
      }
      sum += n;
      ans = min(ans, total);
    }
    return ans % MOD;
  }
};
