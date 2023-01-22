using int64 = long long;

class Solution {
public:
  int64 minOperations(vector<int> &a, vector<int> &b, int k) {
    int n = a.size();
    int64 x = 0, y = 0;
    for (int i = 0; i < n; i++) {
      if (a[i] == b[i])
        continue;

      int64 delta = abs(a[i] - b[i]);
      if (k == 0)
        return -1;
      if (delta % k != 0)
        return -1;

      if (a[i] > b[i])
        x += delta / k;
      else
        y += delta / k;
    }
    return (x == y ? x : -1);
  }
};
