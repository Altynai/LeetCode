class Solution {
public:
  string getSmallestString(int n, int k) {
    string ans(n, 'a');
    k -= n;
    for (int i = n - 1; k > 0 && i >= 0; i--) {
      int del = min(k, 25);
      ans[i] += del;
      k -= del;
    }
    return ans;
  }
};
