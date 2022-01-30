class Solution {
public:
  int findFinalValue(vector<int> &a, int x) {
    set<int> seen(a.begin(), a.end());
    while (seen.count(x))
      x *= 2;
    return x;
  }
};
