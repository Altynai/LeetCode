class Solution {
public:
  int minSwaps(vector<int> &a) {
    int n = a.size();
    vector<vector<int>> pos(2);
    for (int i = 0; i < n; i++)
      pos[a[i] % 2].push_back(i);

    int even = pos[0].size(), odd = pos[1].size();
    int ans = INT_MAX;
    for (int i = 0; i <= 1; i++) {
      if (i == 0 and !(even == odd or even == odd + 1))
        continue;
      if (i == 1 and !(odd == even or odd == even + 1))
        continue;
      int op = 0;
      for (int now = 0, j = 0; j < pos[i].size(); j++, now += 2)
        op += abs(pos[i][j] - now);
      ans = min(ans, op);
    }
    return ans == INT_MAX ? -1 : ans;
  }
};
