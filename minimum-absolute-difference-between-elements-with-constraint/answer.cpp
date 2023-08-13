class Solution {
public:
  int minAbsoluteDifference(vector<int> &a, int x) {
    int n = a.size();
    multiset<int> s;
    for (int i = x; i < n; i++)
      s.insert(a[i]);

    int ans = INT_MAX;
    for (int i = 0; i < n - x; i++) {
      auto it = s.lower_bound(a[i]);
      if (it != s.end())
        ans = min(ans, *it - a[i]);
      if (it != s.begin())
        ans = min(ans, a[i] - *prev(it));
      s.erase(s.find(a[i + x]));
    }
    return ans;
  }
};
