class Solution {
public:
  int sumOfMultiples(int n) {
    int ans = 0;
    for (int i = 1; i <= n; i++) {
      if (i % 3 == 0 or i % 5 == 0 or i % 7 == 0)
        ans += i;
    }
    return ans;
  }
};
