class Solution {
public:
  string largestMerge(string a, string b) {
    int n = a.size(), m = b.size();
    vector<char> ans(n + m, '?');

    for (int i = 0, j = 0, k = 0; k < n + m; k++) {
      if (i == n)
        ans[k] = b[j++];
      else if (j == m)
        ans[k] = a[i++];
      else
        ans[k] = (a.substr(i) > b.substr(j) ? a[i++] : b[j++]);
    }

    return string(ans.begin(), ans.end());
  }
};
