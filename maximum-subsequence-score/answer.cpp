template <typename T>
using min_priority_queue = priority_queue<T, vector<T>, greater<T>>;

using int64 = long long;

class Solution {
public:
  int64 maxScore(vector<int> &a, vector<int> &b, int k) {
    int n = a.size();
    vector<pair<int, int>> c;
    for (int i = 0; i < n; i++)
      c.push_back({b[i], a[i]});

    sort(c.begin(), c.end());
    min_priority_queue<int> q;

    int64 sum = 0;
    for (int i = 0; i < k - 1; i++) {
      sum += c[n - 1 - i].second;
      q.push(c[n - 1 - i].second);
    }

    int64 ans = 0;
    for (int i = n - k; i >= 0; i--) {
      ans = max(ans, 1LL * c[i].first * (sum + c[i].second));

      if (!q.empty() and c[i].second > q.top()) {
        sum -= q.top();
        q.pop();

        q.push(c[i].second);
        sum += c[i].second;
      }
    }
    return ans;
  }
};
