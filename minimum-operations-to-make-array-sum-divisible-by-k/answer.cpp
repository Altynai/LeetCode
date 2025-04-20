class Solution {
public:
  int minOperations(vector<int> &a, int k) {
    return accumulate(a.begin(), a.end(), 0) % k;
  }
};
