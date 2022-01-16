class Solution {
public:
  long long maxRunTime(int n, vector<int> &b) {
    int m = b.size();
    sort(b.begin(), b.end());

    long long low = b[m - n];
    long long high = accumulate(b.begin(), b.end(), 0LL) / n;
    long long ans = -1;
    while (low <= high) {
      long long x = (low + high) / 2;
      int cnt = 0;
      long long sum = 0;
      for (int i = 0; i < m; i++) {
        sum += b[i];
        if (sum >= x) {
          cnt++;
          sum -= x;
        }
      }
      if (cnt >= n)
        ans = x, low = x + 1;
      else
        high = x - 1;
    }
    return ans;
  }
};
