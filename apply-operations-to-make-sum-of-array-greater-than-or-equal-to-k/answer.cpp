class Solution {
public:
  int minOperations(int k) {
    int ans = k - 1;
    for (int i = 2; i < k; i++)
      ans = min(ans, i - 1 + (k + i - 1) / i - 1);
    return ans;
  }
};
