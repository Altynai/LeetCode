class Solution {
public:
  int minNumber(vector<int> &a, vector<int> &b) {
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    for (int x : a) {
      if (count(b.begin(), b.end(), x) > 0)
        return x;
    }
    return min(a[0], b[0]) * 10 + max(a[0], b[0]);
  }
};
