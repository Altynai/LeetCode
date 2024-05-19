class Solution {
public:
  bool isArraySpecial(vector<int> &a) {
    int n = a.size();
    for (int i = 1; i < n; i++) {
      if ((a[i] & 1) == (a[i - 1] & 1))
        return false;
    }
    return true;
  }
};
