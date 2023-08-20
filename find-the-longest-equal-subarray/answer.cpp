class Solution {
public:
  int longestEqualSubarray(vector<int> &a, int k) {
    int n = a.size();
    vector<vector<int>> pos(n + 1);
    for (int i = 0; i < n; i++)
      pos[a[i]].push_back(i);

    int ans = 0;
    vector<int> where(n + 1, -1);
    for (int i = 0; i < n; i++) {
      const vector<int> &p = pos[a[i]];
      int cur = ++where[a[i]];

      int best = 0;
      for (int l = cur, r = p.size() - 1; l <= r;) {
        int mid = (l + r) / 2;
        int total = p[mid] - p[cur] + 1;
        int cnt = mid - cur + 1;
        if (total - cnt <= k)
          best = cnt, l = mid + 1;
        else
          r = mid - 1;
      }
      ans = max(ans, best);
    }
    return ans;
  }
};
