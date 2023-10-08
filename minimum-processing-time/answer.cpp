class Solution {
public:
  int minProcessingTime(vector<int> &time, vector<int> &tasks) {
    sort(time.begin(), time.end());
    sort(tasks.begin(), tasks.end());

    int ans = 0, n = time.size();
    for (int i = 0; i < n; i++)
      ans = max(ans, time[i] + tasks[(n - i) * 4 - 1]);
    return ans;
  }
};
