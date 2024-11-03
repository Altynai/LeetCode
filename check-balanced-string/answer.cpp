class Solution {
public:
  bool isBalanced(string s) {
    int n = s.size();
    vector<int> sum(2, 0);
    for (int i = 0; i < n; i++)
      sum[i % 2] += s[i] - '0';
    return sum[0] == sum[1];
  }
};
