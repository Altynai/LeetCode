class Solution {
public:
  int destroyTargets(vector<int> &a, int space) {
    int n = a.size();

    map<int, vector<int>> p;
    for (int i = 0; i < n; i++) {
      int root = a[i] % space;
      p[root].push_back(a[i]);
    }

    int len = 0, ans = INT_MAX;
    for (auto &[k, v] : p) {
      int minv = *min_element(v.begin(), v.end());
      if (v.size() > len or (v.size() == len and minv < ans)) {
        len = v.size();
        ans = minv;
      }
    }
    return ans;
  }
};
