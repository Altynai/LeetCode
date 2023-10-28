class Solution {
public:
  int sumCounts(vector<int> &a) {
    int ans = 0, n = a.size();
    for (int i = 0; i < n; i++) {
      unordered_set<int> s;
      for (int j = i; j < n; j++) {
        s.insert(a[j]);
        ans += s.size() * s.size();
      }
    }
    return ans;
  }
};
