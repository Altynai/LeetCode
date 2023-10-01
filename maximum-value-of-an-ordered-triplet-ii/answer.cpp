using int64 = long long;

class Solution {
public:
  long long maximumTripletValue(vector<int> &a) {
    int n = a.size();
    int minVal = min(a[0], a[1]), maxVal = max(a[0], a[1]);
    int minDelta = a[0] - a[1], maxDelta = a[0] - a[1];

    int64 ans = 0;
    for (int i = 2; i < n; i++) {
      ans = max(ans, 1LL * minDelta * a[i]);
      ans = max(ans, 1LL * maxDelta * a[i]);

      minDelta = min(minDelta, min(minVal - a[i], maxVal - a[i]));
      maxDelta = max(maxDelta, max(minVal - a[i], maxVal - a[i]));

      minVal = min(minVal, a[i]);
      maxVal = max(maxVal, a[i]);
    }
    return ans;
  }
};
