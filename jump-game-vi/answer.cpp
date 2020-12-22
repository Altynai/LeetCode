class Solution {
public:
  int maxResult(vector<int> &nums, int k) {
    int n = nums.size();
    if (n == 1)
      return nums[0];

    priority_queue<pair<int, int>, vector<pair<int, int>>, less<pair<int, int>>>
        q;
    q.push({nums[0], 0});

    for (int i = 1; i < n; i++) {
      while (q.top().second < i - k)
        q.pop();

      int val = q.top().first + nums[i];
      q.push({val, i});
      if (i == n - 1)
        return val;
    }
    return 0;
  }
};
