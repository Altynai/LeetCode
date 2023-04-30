class Solution {
public:
  int maximizeSum(vector<int> &a, int k) {
    int x = *max_element(a.begin(), a.end());
    return (x + x + k - 1) * k / 2;
  }
};
