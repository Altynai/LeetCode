class Solution {
public:
  int buyChoco(vector<int> &a, int money) {
    sort(a.begin(), a.end());
    int ans = money - a[0] - a[1];
    return ans >= 0 ? ans : money;
  }
};
