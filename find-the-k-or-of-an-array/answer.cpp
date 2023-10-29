class Solution {
public:
  int findKOr(vector<int> &a, int k) {
    int ans = 0;
    for (int i = 0; i < 31; i++) {
      int cnt = 0;
      for (int x : a) {
        if (x & (1 << i))
          cnt++;
      }
      if (cnt >= k)
        ans |= (1 << i);
    }
    return ans;
  }
};
