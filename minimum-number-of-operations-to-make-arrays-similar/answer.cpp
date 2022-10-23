using int64 = long long;

class Solution {
public:
  int64 makeSimilar(vector<int> &a, vector<int> &target) {
    int n = a.size();
    int64 ans = 0;

    for (int mod = 0; mod < 2; mod++) {
      vector<int> b, c;
      for (int x : a) {
        if (x % 2 == mod)
          b.push_back(x);
      }
      for (int x : target) {
        if (x % 2 == mod)
          c.push_back(x);
      }

      sort(b.begin(), b.end());
      sort(c.begin(), c.end());

      int m = b.size();
      for (int i = 0; i < m; i++) {
        if (b[i] > c[i])
          ans += (b[i] - c[i]) / 2;
      }
    }
    return ans;
  }
};
