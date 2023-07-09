class Solution {
public:
  bool checkArray(vector<int> &a, int k) {
    int n = a.size();
    queue<pair<int, int>> q;
    int sum = 0;
    for (int i = 0; i < n; i++) {
      while (q.size() and q.front().first <= i - k) {
        sum -= q.front().second;
        q.pop();
      }
      if (sum > a[i])
        return false;
      int x = a[i] - sum;
      if (i > n - k and x != 0)
        return false;

      if (x > 0 and i <= n - k) {
        q.push({i, x});
        sum += x;
      }
    }

    return true;
  }
};
