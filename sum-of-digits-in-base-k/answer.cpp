class Solution {
public:
  int sumBase(int n, int k) {
    int ans = 0;
    for (; n; n /= k)
      ans += n % k;
    return ans;
  }
};
