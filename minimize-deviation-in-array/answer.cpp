class Solution {
public:
  int minimumDeviation(vector<int> &nums) {
    priority_queue<pair<int, int>, vector<pair<int, int>>,
                   greater<pair<int, int>>>
        pq;

    int ma = 0;
    for (int num : nums) {
      int x = num;
      while (x % 2 == 0)
        x /= 2;
      pq.push({x, num});
      ma = max(ma, x);
    }

    int ans = INT_MAX;
    while (pq.top().first < pq.top().second ||
           (pq.top().first == pq.top().second && pq.top().first & 1)) {
      auto [x, y] = pq.top();
      pq.pop();
      ans = min(ans, ma - x);
      x *= 2;
      ma = max(ma, x);
      pq.push(make_pair(x, y));
    }
    ans = min(ans, ma - pq.top().first);
    return ans;
  }
};
