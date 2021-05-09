class Solution {
public:
  int minOperations(vector<int> &a) {
    int ans = 0, pre = a[0] - 1;
    for (int val : a) {
      int nval = max(val, pre + 1);
      ans += abs(nval - val);
      pre = nval;
    }
    return ans;
  }
};
