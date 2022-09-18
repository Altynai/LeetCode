class Solution {
public:
  int matchPlayersAndTrainers(vector<int> &a, vector<int> &b) {
    sort(a.begin(), a.end());
    multiset<int> c(b.begin(), b.end());
    int ans = 0, n = a.size();
    for (int i = n - 1; i >= 0; i--) {
      auto it = c.lower_bound(a[i]);
      if (it != c.end()) {
        ans++;
        c.erase(it);
      }
    }
    return ans;
  }
};
