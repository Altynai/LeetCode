class Solution {
public:
  int semiOrderedPermutation(vector<int> &a) {
    int n = a.size();
    int x = find(a.begin(), a.end(), 1) - a.begin();
    int y = find(a.begin(), a.end(), n) - a.begin();
    if (x < y)
      return x + (n - 1 - y);
    return x + (n - 1 - y) - 1;
  }
};
