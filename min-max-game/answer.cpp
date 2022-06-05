class Solution {
public:
  int minMaxGame(vector<int> &a) {
    while (a.size() > 1) {
      int n = a.size() / 2;
      vector<int> b(n);
      for (int i = 0; i < n; i++) {
        if (i & 1)
          b[i] = max(a[i * 2], a[i * 2 + 1]);
        else
          b[i] = min(a[i * 2], a[i * 2 + 1]);
      }
      a = b;
    }
    return a[0];
  }
};
