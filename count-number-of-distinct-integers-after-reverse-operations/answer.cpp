class Solution {
public:
  int countDistinctIntegers(vector<int> &a) {
    unordered_set<int> s(a.begin(), a.end());
    for (int x : a) {
      int y = 0;
      while (x > 0)
        y = y * 10 + x % 10, x /= 10;
      s.insert(y);
    }
    return s.size();
  }
};
