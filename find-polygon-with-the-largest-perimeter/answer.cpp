using int64 = long long;

class Solution {
public:
  long long largestPerimeter(vector<int> &a) {
    sort(a.begin(), a.end());
    int n = a.size();
    int64 ans = -1, sum = accumulate(a.begin(), a.end(), 0LL);
    for (int i = n - 1; i >= 2; i--) {
      if (sum - a[i] > a[i])
        ans = max(ans, sum);
      sum -= a[i];
    }
    return ans;
  }
};
