class Solution {
public:
  int numberOfArrays(vector<int> &d, int lower, int upper) {
    long long mi = 0, ma = 0, cur = 0;
    for (int x : d) {
      cur += x;
      mi = min(cur, mi);
      ma = max(cur, ma);
    }

    long long x = ma - mi + 1;
    long long y = (long long)upper - lower + 1;
    return x > y ? 0 : y - x + 1;
  }
};
