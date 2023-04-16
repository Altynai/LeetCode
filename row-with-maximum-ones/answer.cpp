class Solution {
public:
  vector<int> rowAndMaximumOnes(vector<vector<int>> &a) {
    int n = a.size();
    int row = 0, cnt = count(a[0].begin(), a[0].end(), 1);
    for (int i = 1; i < n; i++) {
      int c = count(a[i].begin(), a[i].end(), 1);
      if (c > cnt)
        row = i, cnt = c;
    }
    return {row, cnt};
  }
};
