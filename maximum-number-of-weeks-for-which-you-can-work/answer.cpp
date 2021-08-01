class Solution {
public:
  long long numberOfWeeks(vector<int> &a) {
    int n = a.size();
    if (n == 1)
      return 1;

    long long sum = 0, ma = 0;
    for (int x : a) {
      sum += x;
      ma = max(1LL * x, ma);
    }
    if (ma > sum - ma)
      return (sum - ma) * 2 + 1;
    return sum;
  }
};
