using int64 = long long;

class Solution {
public:
  int minOperations(vector<int> &a, int target) {
    int64 sum = accumulate(a.begin(), a.end(), 0LL);
    if (sum < target)
      return -1;

    sort(a.begin(), a.end());
    int ans = 0;
    while (target > 0) {
      int val = a.back();
      a.pop_back();

      if (sum - val >= target) {
        sum -= val;
        continue;
      }
      if (val <= target)
        target -= val, sum -= val;
      else {
        ans++;
        a.push_back(val / 2);
        a.push_back(val / 2);
      }
    }
    return ans;
  }
};
