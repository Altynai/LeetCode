using int64 = long long;

class Solution {
public:
  long long minSum(vector<int> &a, vector<int> &b) {
    vector<int64> sum(2, 0), zero(2, 0);
    for (int x : a) {
      if (x == 0)
        zero[0]++;
      else
        sum[0] += x;
    }
    for (int x : b) {
      if (x == 0)
        zero[1]++;
      else
        sum[1] += x;
    }

    if (zero[0] == 0) {
      if (zero[1] == 0)
        return (sum[0] == sum[1] ? sum[0] : -1);
      else
        return (sum[0] > sum[1] and sum[0] - sum[1] >= zero[1] ? sum[0] : -1);
    } else {
      // zero[0] != 0
      if (zero[1] == 0)
        return (sum[1] > sum[0] and sum[1] - sum[0] >= zero[0] ? sum[1] : -1);
      else
        return max(sum[0] + zero[0], sum[1] + zero[1]);
    }
  }
};
