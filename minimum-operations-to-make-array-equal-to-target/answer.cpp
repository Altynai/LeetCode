using int64 = long long;

class Solution {
public:
  long long minimumOperations(vector<int> &a, vector<int> &b) {
    int n = a.size();
    int64 ans = 0, incr = 0, decr = 0;
    for (int i = 0; i < n; i++) {
      int diff = a[i] - b[i];
      if (diff > 0) {
        if (diff > incr)
          ans += diff - incr;
        incr = diff, decr = 0;
      } else if (diff < 0) {
        diff = abs(diff);
        if (diff > decr)
          ans += diff - decr;
        decr = diff, incr = 0;
      } else
        incr = decr = 0;
    }
    return ans;
  }
};
