class Solution {
public:
  vector<int> findIntersectionValues(vector<int> &a, vector<int> &b) {
    int n = 0, m = 0;
    for (int x : a) {
      if (find(b.begin(), b.end(), x) != b.end())
        n++;
    }
    for (int x : b) {
      if (find(a.begin(), a.end(), x) != a.end())
        m++;
    }
    return {n, m};
  }
};
