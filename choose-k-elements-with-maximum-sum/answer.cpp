template <typename T>
using min_priority_queue = priority_queue<T, vector<T>, greater<T>>;

using int64 = long long;

class Solution {
public:
  vector<long long> findMaxSum(vector<int> &a, vector<int> &b, int k) {
    int n = a.size();

    vector<pair<int, int>> c(n);
    for (int i = 0; i < n; i++)
      c[i] = {a[i], i};
    sort(c.begin(), c.end());

    vector<int64> ans(n);
    int64 sum = 0;
    min_priority_queue<int> que;

    for (int i = 0, j; i < n;) {
      j = i;
      while (j < n and c[j].first == c[i].first)
        ans[c[j++].second] = sum;
      while (i < j) {
        que.push(b[c[i].second]);
        sum += b[c[i].second];
        if (que.size() > k) {
          sum -= que.top();
          que.pop();
        }
        i++;
      }
    }
    return ans;
  }
};
