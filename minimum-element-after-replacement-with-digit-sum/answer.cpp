class Solution {
public:
  int minElement(vector<int> &a) {
    int ans = INT_MAX, sum;
    for (int x : a) {
      for (sum = 0; x > 0; x /= 10)
        sum += x % 10;
      ans = min(ans, sum);
    }
    return ans;
  }
};
