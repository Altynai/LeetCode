class Solution {
public:
  int triangularSum(vector<int> &a) {
    while (a.size() > 1) {
      int n = a.size();
      vector<int> b(n - 1);
      for (int i = 0; i + 1 < n; i++)
        b[i] = (a[i] + a[i + 1]) % 10;
      a = b;
    }
    return a[0];
  }
};
