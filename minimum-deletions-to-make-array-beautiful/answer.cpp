class Solution {
public:
  int minDeletion(vector<int> &a) {
    int n = a.size(), ans = 0;
    for (int i = 0, j = 1; j < n;) {
      if (a[i] == a[j]) {
        ans++;
        j++;
      } else {
        i = j + 1;
        j = i + 1;
      }
    }
    if ((n - ans) & 1)
      ans++;
    return ans;
  }
};
