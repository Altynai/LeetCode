class Solution {
public:
  int largestInteger(int num) {
    string s = to_string(num);
    int n = s.size();

    vector<vector<int>> d(2);
    for (int i = 0; i < n; i++)
      d[(s[i] - '0') % 2].push_back(s[i] - '0');

    sort(d[0].begin(), d[0].end());
    sort(d[1].begin(), d[1].end());

    int ans = 0;
    for (int i = 0; i < n; i++) {
      int k = ((s[i] - '0') & 1);
      ans = ans * 10 + d[k].back();
      d[k].pop_back();
    }
    return ans;
  }
};
