
class Solution {
public:
  vector<int> getGoodIndices(vector<vector<int>> &variables, int target) {

    // x ^ y % mod
    auto pow = [](int x, int y, int mod) -> int {
      int res = 1, p = x;
      while (y) {
        if (y & 1)
          res = res * p % mod;
        p = p * p % mod;
        y /= 2;
      }
      return res;
    };

    vector<int> ans;
    int n = variables.size();
    for (int i = 0; i < n; i++) {
      int x = pow(variables[i][0], variables[i][1], 10);
      if (pow(x, variables[i][2], variables[i][3]) == target)
        ans.push_back(i);
    }
    return ans;
  }
};
