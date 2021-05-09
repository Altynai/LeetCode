class Solution {
public:
  int maxFrequency(vector<int> &a, int k) {
    sort(a.begin(), a.end());
    int n = a.size();
    deque<int> dq;
    int sum = 0, ans = 0;
    for (int i = 0; i < n; i++) {
      dq.push_back(a[i]);
      sum += a[i];
      while (dq.size() * a[i] - sum > k) {
        sum -= dq.front();
        dq.pop_front();
      }
      ans = max(ans, (int)dq.size());
    }
    return ans;
  }
};
