class Solution {
public:
  int maxSum(vector<int> &a) {
    int n = a.size(), ans = -1;
    for (int i = 0; i < n; i++) {
      string s = to_string(a[i]);
      int x = *max_element(s.begin(), s.end()) - '0';
      for (int j = i + 1; j < n; j++) {
        string t = to_string(a[j]);
        int y = *max_element(t.begin(), t.end()) - '0';
        if (x == y)
          ans = max(ans, a[i] + a[j]);
      }
    }
    return ans;
  }
};
