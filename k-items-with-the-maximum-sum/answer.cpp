class Solution {
public:
  int kItemsWithMaximumSum(int numOnes, int numZeros, int numNegOnes, int k) {
    int ans = 0;

    int d = min(k, numOnes);
    ans += d, k -= d;

    d = min(k, numZeros);
    k -= d;

    d = min(k, numNegOnes);
    ans -= d, k -= d;
    return ans;
  }
};
