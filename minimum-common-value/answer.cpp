class Solution {
public:
  int getCommon(vector<int> &a, vector<int> &b) {
    int n = a.size(), m = b.size();
    for (int i = 0, j = 0; i < n and j < m;) {
      if (a[i] == b[j])
        return a[i];
      else if (a[i] < b[j])
        i++;
      else
        j++;
    }
    return -1;
  }
};
