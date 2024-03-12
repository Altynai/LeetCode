class Solution {
public:
  int minimumBoxes(vector<int> &apple, vector<int> &capacity) {
    int sum = accumulate(apple.begin(), apple.end(), 0);
    sort(capacity.rbegin(), capacity.rend());

    int ans = 0, m = capacity.size();
    for (int i = 0; sum > 0 and i < m; i++)
      sum -= capacity[i], ans++;
    return ans;
  }
};
