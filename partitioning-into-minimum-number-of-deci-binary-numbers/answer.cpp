class Solution {
public:
  int minPartitions(string s) {
    int ans = 0;
    for (char ch : s) {
      ans = max(ans, ch - '0');
    }
    return ans;
  }
};
