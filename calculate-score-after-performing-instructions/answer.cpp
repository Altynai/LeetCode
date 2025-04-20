using int64 = long long;

class Solution {
public:
  long long calculateScore(vector<string> &s, vector<int> &vals) {
    int n = s.size();
    int64 ans = 0;
    vector<bool> vis(n, 0);

    int x = 0;
    while (x >= 0 and x < n and !vis[x]) {
      vis[x] = 1;
      if (s[x][0] == 'a') {
        ans += vals[x];
        x++;
      } else {
        x += vals[x];
      }
    }
    return ans;
  }
};
