#define bit(n, i) (((n) >> (i)) & 1)

class Solution {
public:
  int longestSubarray(vector<int> &a) {
    int n = a.size();
    int k = a[0], ans = 1;
    int val = a[0], cnt = 1;
    for (int i = 1; i < n; i++) {
      if (a[i] == a[i - 1])
        cnt++;
      else
        val = a[i], cnt = 1;

      if (val > k or (val == k and cnt > ans))
        k = val, ans = cnt;
    }
    return ans;
  }
};
