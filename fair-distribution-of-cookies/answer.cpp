class Solution {
public:
  int distributeCookies(vector<int> &a, int k) {
    int n = a.size();
    int ans = INT_MAX;
    vector<int> b(k, 0);

    function<void(int)> dfs = [&](int i) {
      if (i == n) {
        ans = min(ans, *max_element(b.begin(), b.end()));
        return;
      }
      for (int j = 0; j < k; j++) {
        if (b[j] + a[i] >= ans)
          continue;

        b[j] += a[i];
        dfs(i + 1);
        b[j] -= a[i];
      }
    };
    dfs(0);
    return ans;
  }
};
