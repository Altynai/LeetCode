class Solution {
public:
  int latestTimeCatchTheBus(vector<int> &a, vector<int> &b, int cap) {
    int n = a.size(), m = b.size();
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());

    int ans = 0;
    unordered_set<int> seen(b.begin(), b.end());
    auto updateAns = [&](int t) {
      if (seen.count(t) == 0)
        ans = max(ans, t);
    };

    int j = 0;
    for (int i = 0; i < n; i++) {
      int cnt = 0;
      while (j < m and b[j] <= a[i] and cnt < cap) {
        // cut the line before passenger j
        updateAns(b[j] - 1);
        j++;
        cnt++;
      }
      // current bus is not full, we can wait until its departure time
      if (cnt < cap)
        updateAns(a[i]);
    }
    return ans;
  }
};
