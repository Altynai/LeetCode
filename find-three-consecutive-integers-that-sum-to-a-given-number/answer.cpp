class Solution {
public:
  vector<long long> sumOfThree(long long x) {
    if (x % 3 != 0)
      return {};
    long long y = x / 3;
    return {y - 1, y, y + 1};
  }
};
