class Solution {
public:
  bool canMakeEqual(vector<int> &a, int k) {
    int n = a.size();
    for (int x = -1; x <= 1; x += 2) {
      vector<int> b = a;
      int cnt = 0;
      for (int i = 0; i < n - 1; i++) {
        if (b[i] != x) {
          b[i + 1] *= -1;
          cnt++;
        }
      }
      if (b[n - 1] == x and cnt <= k)
        return 1;
    }
    return 0;
  }
};
