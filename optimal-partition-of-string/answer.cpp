class Solution {
public:
  int partitionString(string s) {
    int n = s.size(), ans = 0;
    for (int i = 0; i < n;) {
      int j = i;
      vector<bool> vis(26, 0);
      while (j < n and !vis[s[j] - 'a'])
        vis[s[j++] - 'a'] = 1;
      ans++;
      i = j;
    }
    return ans;
  }
};
