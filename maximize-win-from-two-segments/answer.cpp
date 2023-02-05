template <class T> bool umax(T &a, const T b) { return a < b ? a = b, 1 : 0; }

class Solution {
public:
  int maximizeWin(vector<int> &a, int k) {
    int n = a.size();

    vector<int> f(n, 1);
    for (int l = 0, r = 0; r < n; r++) {
      while (l < r and a[l] < a[r] - k)
        l++;
      umax(f[r], r - l + 1);
      if (r > 0)
        umax(f[r], f[r - 1]);
    }

    vector<int> g(n, 1);
    for (int l = n - 1, r = n - 1; l >= 0; l--) {
      while (l < r and a[r] > a[l] + k)
        r--;
      umax(g[l], r - l + 1);
      if (l + 1 < n)
        umax(g[l], g[l + 1]);
    }

    int ans = 1;
    for (int i = 0; i + 1 < n; i++)
      ans = max(ans, f[i] + g[i + 1]);
    return ans;
  }
};
