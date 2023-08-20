class Solution {
public:
  int minimumSum(int n, int k) {
    set<int> seen;
    int cnt = 0, i = 1, sum = 0;
    while (cnt < n) {
      if (seen.count(k - i) == 0) {
        cnt++, sum += i;
        seen.insert(i);
      }
      i++;
    }
    return sum;
  }
};
