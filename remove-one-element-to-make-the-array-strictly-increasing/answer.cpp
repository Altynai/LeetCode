class Solution {
public:
  bool canBeIncreasing(vector<int> &a) {
    int n = a.size();
    for (int i = 0; i < n; i++) {
      vector<int> b = a;
      b.erase(b.begin() + i);
      if (adjacent_find(b.begin(), b.end(), greater_equal<int>()) == b.end())
        return 1;
    }
    return 0;
  }
};
