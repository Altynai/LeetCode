class Solution {
public:
  int kIncreasing(vector<int> &a, int k) {
    int n = a.size(), ans = 0;
    for (int i = 0; i < k; i++) {
      vector<int> s;
      int cnt = 0;
      for (int j = i; j < n; j += k) {
        auto it = upper_bound(s.begin(), s.end(), a[j]);
        if (it == s.end())
          s.push_back(a[j]);
        else
          *it = a[j];
        cnt++;
      }
      ans += cnt - s.size();
    }
    return ans;
  }
};
