class Solution {
public:
  int countPairs(vector<vector<int>> &coordinates, int k) {
    int ans = 0, n = coordinates.size();
    map<pair<int, int>, int> cnt;
    for (int i = 0; i < n; i++) {
      int x = coordinates[i][0], y = coordinates[i][1];
      for (int a = 0; a <= k; a++) {
        int x2 = x ^ a;
        int y2 = y ^ (k - a);
        auto it = cnt.find({x2, y2});
        if (it != cnt.end())
          ans += it->second;
      }
      cnt[{x, y}]++;
    }
    return ans;
  }
};
