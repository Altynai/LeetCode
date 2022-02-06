template <typename T>
using min_priority_queue = priority_queue<T, vector<T>, greater<T>>;

#define i64 long long

class Solution {
public:
  i64 minimumDifference(vector<int> &a) {
    int n = a.size() / 3;

    min_priority_queue<int> x;
    i64 sum = 0;
    for (int i = n * 2; i < n * 3; i++)
      x.push(a[i]), sum += a[i];

    vector<i64> suffix(n * 3, -1);
    suffix[n * 2] = sum;
    for (int i = n * 2 - 1; i >= n; i--) {
      x.push(a[i]), sum += a[i];
      sum -= x.top(), x.pop();
      suffix[i] = sum;
    }

    sum = 0;
    priority_queue<int> y;
    for (int i = 0; i < n; i++)
      y.push(a[i]), sum += a[i];

    i64 ans = sum - suffix[n];
    for (int i = n; i < n * 2; i++) {
      y.push(a[i]), sum += a[i];
      sum -= y.top(), y.pop();
      ans = min(ans, sum - suffix[i + 1]);
    }
    return ans;
  }
};
