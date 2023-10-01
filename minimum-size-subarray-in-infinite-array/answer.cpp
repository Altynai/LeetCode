using int64 = long long;

class Solution {
private:
  int find(vector<int> &a, int target) {
    if (target == 0)
      return 0;
    int ans = INT_MAX, n = a.size();

    unordered_map<int64, int> pos;
    int64 sum = 0;
    pos[sum] = 0;
    for (int i = 1; i <= n * 2; i++) {
      sum += a[i > n ? i - n - 1 : i - 1];
      auto it = pos.find(sum - target);
      if (it != pos.end())
        ans = min(ans, i - (it->second));
      pos[sum] = i;
    }
    return ans;
  }

public:
  int minSizeSubarray(vector<int> &a, int target) {
    int ans = find(a, target), n = a.size();

    bool good = 1;
    int sum = 0;
    for (int x : a) {
      sum += x;
      if (sum >= target) {
        good = 0;
        break;
      }
    }
    if (good) {
      int res = find(a, target % sum);
      if (res != INT_MAX)
        ans = min(ans, target / sum * n + res);
    }

    if (ans == INT_MAX)
      ans = -1;
    return ans;
  }
};
