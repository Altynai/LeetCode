class Solution {
public:
  int findNonMinOrMax(vector<int> &a) {
    int n = a.size();
    sort(a.begin(), a.end());
    return n <= 2 ? -1 : a[1];
  }
};
