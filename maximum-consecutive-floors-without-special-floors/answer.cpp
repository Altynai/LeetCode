class Solution {
public:
  int maxConsecutive(int bottom, int top, vector<int> &a) {
    a.push_back(bottom - 1);
    a.push_back(top + 1);
    sort(a.begin(), a.end());

    int n = a.size(), ans = 0;
    for (int i = 1; i < n; i++)
      ans = max(ans, a[i] - a[i - 1] - 1);
    return ans;
  }
};
