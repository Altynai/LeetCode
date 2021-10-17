class Solution {
public:
  int minMovesToSeat(vector<int> &a, vector<int> &b) {
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    int n = a.size(), ans = 0;
    for (int i = 0; i < n; i++)
      ans += abs(a[i] - b[i]);
    return ans;
  }
};
