class Solution {
public:
  int maxLengthBetweenEqualCharacters(string s) {
    vector<int> p(26, -1);
    int ans = -1;
    for (int i = 0; i < s.size(); i++) {
      int j = s[i] - 'a';
      if (p[j] != -1)
        ans = max(ans, i - p[j] - 1);
      if (p[j] == -1)
        p[j] = i;
    }
    return ans;
  }
};
