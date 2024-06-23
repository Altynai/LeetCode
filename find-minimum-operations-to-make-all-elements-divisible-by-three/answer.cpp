class Solution {
public:
  int minimumOperations(vector<int> &a) {
    int ans = 0;
    for (int x : a) {
      int y = x % 3;
      ans += min(y, 3 - y);
    }
    return ans;
  }
};
