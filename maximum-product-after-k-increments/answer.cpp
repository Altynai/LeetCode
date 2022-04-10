template <typename T>
using min_priority_queue = priority_queue<T, vector<T>, greater<T>>;

const int MOD = 1e9 + 7;

class Solution {
public:
  int maximumProduct(vector<int> &a, int k) {
    int n = a.size();
    if (n == 1)
      return a[0] + k;

    min_priority_queue<int> q;
    for (int x : a)
      q.push(x);

    while (k > 0) {
      int x = q.top();
      q.pop();
      int d = (x == q.top() ? 1 : min(k, q.top() - x));
      k -= d;
      q.push(x + d);
    }

    int ans = 1;
    while (!q.empty()) {
      ans = 1LL * ans * q.top() % MOD;
      q.pop();
    }
    return ans;
  }
};
