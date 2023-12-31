class Solution {
public:
  bool hasTrailingZeros(vector<int> &a) {
    unordered_set<int> s;
    for (int x : a) {
      for (int y : s) {
        if ((x | y) % 2 == 0)
          return 1;
      }
      s.insert(x);
    }
    return 0;
  }
};
