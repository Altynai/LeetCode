using pii = pair<int, int>;

class Solution {
public:
  vector<int> kthSmallestPrimeFraction(vector<int> &a, int k) {
    auto cmp = [](const pii &lh, const pii &rh) {
      return lh.first * rh.second < rh.first * lh.second;
    };

    priority_queue<pii, vector<pii>, decltype(cmp)> que(cmp);
    int n = a.size();
    for (int i = 0; i < n; i++) {
      for (int j = i + 1; j < n; j++) {
        pii p = {a[i], a[j]};
        if (que.size() + 1 <= k)
          que.push(p);
        else if (cmp(p, que.top())) {
          que.pop();
          que.push(p);
        }
      }
    }
    return {que.top().first, que.top().second};
  }
};
