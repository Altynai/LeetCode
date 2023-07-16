class Solution {
public:
  int sumOfSquares(vector<int> &a) {
    int n = a.size(), sum = 0;
    for (int i = 1; i <= n; i++) {
      if (n % i == 0)
        sum += a[i - 1] * a[i - 1];
    }
    return sum;
  }
};
