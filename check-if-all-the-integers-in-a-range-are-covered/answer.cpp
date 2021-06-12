class Solution {
public:
  bool isCovered(vector<vector<int>> &a, int l, int r) {
    int n = a.size();
    for (int i = l; i <= r; i++) {
      int found = 0;
      for (int j = 0; !found && j < n; j++) {
        if (a[j][0] <= i && i <= a[j][1])
          found = 1;
      }
      if (!found)
        return 0;
    }
    return 1;
  }
};
