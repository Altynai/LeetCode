class Solution {
public:
  vector<long long> getDistances(vector<int> &a) {
    int n = a.size();
    unordered_map<int, vector<int>> p;
    for (int i = 0; i < n; i++)
      p[a[i]].push_back(i);

    vector<long long> ans(n, 0);
    for (auto &[val, pos] : p) {
      int m = pos.size();
      long long pfx = 0, sfx = accumulate(pos.begin(), pos.end(), 0LL);
      for (int i = 0; i < m; i++) {
        sfx -= pos[i];
        pfx += pos[i];
        ans[pos[i]] =
            sfx - 1LL * (m - i - 1) * pos[i] + 1LL * pos[i] * (i + 1) - pfx;
      }
    }
    return ans;
  }
};
