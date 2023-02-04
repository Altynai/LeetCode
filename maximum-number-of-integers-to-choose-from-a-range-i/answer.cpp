class Solution {
public:
  int maxCount(vector<int> &banned, int n, int maxSum) {
    sort(banned.begin(), banned.end());
    int i = 0, m = banned.size();
    int cnt = 0, sum = 0;
    for (int j = 1; j <= n; j++) {
      while (i < m and banned[i] < j)
        i++;
      if (i < m and j == banned[i])
        continue;
      if (sum + j <= maxSum)
        cnt++, sum += j;
      else
        break;
    }
    return cnt;
  }
};
