class Solution {
public:
  int captureForts(vector<int> &a) {
    int n = a.size(), prev = -1, ans = 0;
    for (int i = 0; i < n; i++) {
      if (a[i] != 0) {
        if (a[i] == 1 and prev != -1 and a[prev] == -1)
          ans = max(ans, abs(i - prev) - 1);
        if (a[i] == -1 and prev != -1 and a[prev] == 1)
          ans = max(ans, abs(i - prev) - 1);
        prev = i;
      }
    }
    return ans;
  }
};
