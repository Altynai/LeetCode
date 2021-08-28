class Solution {
public:
  long long maxMatrixSum(vector<vector<int>> &matrix) {
    long long ans = 0;
    int negative = 0, mi = INT_MAX, zero = 0;
    for (auto &row : matrix) {
      for (int val : row) {
        if (val == 0)
          zero++;
        else if (val < 0)
          negative++;

        val = abs(val);
        mi = min(val, mi);
        ans += val;
      }
    }

    if (negative % 2 == 0 || zero > 0)
      return ans;
    return ans - mi * 2;
  }
};
