using int64 = long long;

class Solution {
public:
  int64 kSum(vector<int> &a, int k) {
    int n = a.size();
    int64 sum = 0;
    for (int &x : a) {
      if (x >= 0)
        sum += x;
      x = abs(x);
    }

    sort(a.begin(), a.end());
    priority_queue<pair<int64, int>> q;
    q.push({sum - a[0], 0});

    for (; k > 1; k--) {
      auto [s, i] = q.top();
      q.pop();

      sum = s;
      if (i + 1 < n) {
        q.push({sum + a[i] - a[i + 1], i + 1});
        q.push({sum - a[i + 1], i + 1});
      }
    }
    return sum;
  }
};
