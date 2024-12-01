class Solution {
public:
  int smallestNumber(int n) {
    int ans = 1;
    while (ans < n)
      ans = ans * 2 + 1;
    return ans;
  }
};
