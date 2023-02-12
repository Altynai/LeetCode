class Solution {
public:
  int minimumScore(string s, string t) {
    int n = s.size(), m = t.size();

    int ans = m;
    vector<int> idx(m, -1);
    for (int j = m - 1, i = n - 1; j >= 0; j--) {
      while (i >= 0 and s[i] != t[j])
        i--;
      idx[j] = i;
      if (i >= 0 and s[i] == t[j])
        i--;

      // remove the entire prefix
      if (idx[j] != -1)
        ans = min(ans, j);
    }

    for (int j = 0, k = 0; j < m; j++) {
      while (k < n and s[k] != t[j])
        k++;
      if (k < n) {
        int pos = -1;
        for (int l = j + 1, r = m - 1; l <= r;) {
          int mid = (l + r) / 2;
          if (idx[mid] != -1 and idx[mid] > k)
            pos = mid, r = mid - 1;
          else
            l = mid + 1;
        }
        if (pos != -1) {
          ans = min(ans, pos - j - 1);
        } else {
          ans = min(ans, m - j - 1);
        }
      }

      if (k < n and s[k] == t[j])
        k++;
    }
    return ans;
  }
};
