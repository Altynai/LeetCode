class Solution {
public:
  int maximumSum(vector<int> &a) {
    map<int, pair<int, int>> p;
    for (int x : a) {
      int sum = 0, y = x;
      while (y > 0)
        sum += y % 10, y /= 10;

      if (p.count(sum) == 0)
        p[sum] = {-1, -1};
      pair<int, int> &pr = p.find(sum)->second;
      if (pr.first == -1 or x >= pr.first) {
        pr.second = pr.first;
        pr.first = x;
      } else if (x > pr.second) {
        pr.second = x;
      }
    }

    int ans = -1;
    for (auto [k, pr] : p)
      if (pr.second != -1) {
        ans = max(ans, pr.first + pr.second);
      }
    return ans;
  }
};
