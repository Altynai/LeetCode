class Solution {
public:
  int maximumCandies(vector<int> &a, long long k) {
    int n = a.size(), ans = 0;
    for (int l = 1, r = *max_element(a.begin(), a.end()); l <= r;) {
      int mid = (l + r) / 2;
      long long cnt = 0;
      for (int x : a)
        cnt += x / mid;
      if (cnt >= k)
        ans = mid, l = mid + 1;
      else
        r = mid - 1;
    }
    return ans;
  }
};
