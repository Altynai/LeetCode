class Solution {
public:
  vector<int> findThePrefixCommonArray(vector<int> &a, vector<int> &b) {
    int n = a.size(), cnt = 0;
    vector<int> ans(n, 0);
    vector<bool> visa(n, 0), visb(n, 0);
    for (int i = 0; i < n; i++) {
      if (a[i] == b[i])
        cnt++;
      else {
        if (visb[a[i]])
          cnt++;
        if (visa[b[i]])
          cnt++;
      }
      visa[a[i]] = visb[b[i]] = 1;
      ans[i] = cnt;
    }
    return ans;
  }
};
