class Solution {
public:
  string mergeAlternately(string a, string b) {
    int n = a.size(), m = b.size();
    int i = 0, j = 0;
    string ans = "";
    while (i < n && j < m) {
      ans += a[i++];
      ans += b[j++];
    }
    while (i < n)
      ans += a[i++];
    while (j < m)
      ans += b[j++];
    return ans;
  }
};
