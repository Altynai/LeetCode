class Solution {
public:
  long long flowerGame(int n, int m) {
    int odd0 = (n + 1) / 2;
    int odd1 = (m + 1) / 2;
    return 1LL * odd0 * (m - odd1) + 1LL * (n - odd0) * odd1;
  }
};
