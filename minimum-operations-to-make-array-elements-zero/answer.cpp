using int64 = long long;

class Solution {
public:
  long long minOperations(vector<vector<int>> &q) {
    int n = q.size();
    int64 ans = 0;
    for (int i = 0; i < n; i++) {
      int64 l = q[i][0], r = q[i][1];

      int64 start = 1, total = 0, op = 1;
      for (; start <= r; start *= 4, op++) {
        int64 end = start * 4 - 1;
        if (end < l)
          continue;

        if (start < l)
          total += op * (min(end, r) - l + 1);
        else
          total += op * (min(end, r) - start + 1);
      }
      ans += (total + 1) / 2;
    }
    return ans;
  }
};
