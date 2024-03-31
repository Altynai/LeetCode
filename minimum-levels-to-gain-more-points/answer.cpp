class Solution {
public:
  int minimumLevels(vector<int> &p) {
    int n = p.size(), sum = 0;
    for (int i = 0; i < n; i++)
      sum += (p[i] == 1 ? 1 : -1);
    for (int i = 0, got = 0; i < n - 1; i++) {
      got += (p[i] == 1 ? 1 : -1);
      if (got > sum - got)
        return i + 1;
    }
    return -1;
  }
};
