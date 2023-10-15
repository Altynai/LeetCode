class Solution {
public:
  string shortestBeautifulSubstring(string s, int k) {
    int n = s.size();
    vector<int> pos;
    for (int i = 0; i < n; i++) {
      if (s[i] == '1')
        pos.push_back(i);
    }

    int m = pos.size();
    if (m < k)
      return "";

    int len = INT_MAX;
    for (int i = k - 1; i < m; i++)
      len = min(len, pos[i] - pos[i - k + 1] + 1);

    string ans = "";
    for (int i = k - 1; i < m; i++) {
      int l = pos[i] - pos[i - k + 1] + 1;
      if (l > len)
        continue;
      string t = s.substr(pos[i - k + 1], len);
      if (ans == "" or t < ans)
        ans = t;
    }
    return ans;
  }
};
