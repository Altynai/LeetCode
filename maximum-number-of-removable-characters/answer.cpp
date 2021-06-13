class Solution {
public:
  int maximumRemovals(string s, string p, vector<int> &removable) {
    int n = s.size(), m = removable.size();
    vector<int> pos(n, INT_MAX);
    for (int i = 0; i < m; i++)
      pos[removable[i]] = i;

    int ans = 0;
    for (int l = 0, r = m - 1; l <= r;) {
      int mid = (l + r) >> 1;
      // [0, 1 , ... mid]
      int i = 0, j = 0, k = p.size();
      while (i < n && j < k) {
        if (pos[i] > mid && s[i] == p[j])
          j++;
        i++;
      }
      if (j == k) {
        l = ans = mid + 1;
      } else {
        r = mid - 1;
      }
    }
    return ans;
  }
};
