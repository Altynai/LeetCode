#define int64 long long

class Solution {
public:
  int waysToSplitArray(vector<int> &a) {
    int64 sum = 0;
    for (int x : a)
      sum += x;

    int ans = 0, n = a.size();
    int64 now = 0;
    for (int i = 0; i < n - 1; i++) {
      now += a[i];
      if (now >= sum - now)
        ans++;
    }
    return ans;
  }
};
