template <typename T>
using min_priority_queue = priority_queue<T, vector<T>, greater<T>>;

class Solution {
public:
  int maximumBags(vector<int> &a, vector<int> &b, int m) {
    int ans = 0;
    min_priority_queue<int> que;

    int n = a.size();
    for (int i = 0; i < n; i++) {
      if (a[i] == b[i])
        ans++;
      else
        que.push(a[i] - b[i]);
    }
    while (!que.empty() and m >= que.top()) {
      ans++;
      m -= que.top();
      que.pop();
    }
    return ans;
  }
};
