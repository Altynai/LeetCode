class Solution {
public:
  int countPartitions(vector<int> &a) {
    int sum = accumulate(a.begin(), a.end(), 0);
    int ans = 0, n = a.size();
    for (int i = 0, now = 0; i < n - 1; i++) {
      now += a[i];
      if (abs(now - (sum - now)) % 2 == 0)
        ans++;
    }
    return ans;
  }
};
