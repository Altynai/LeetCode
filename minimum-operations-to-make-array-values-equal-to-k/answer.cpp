class Solution {
public:
  int minOperations(vector<int> &a, int k) {
    set<int> s(a.begin(), a.end());
    int n = s.size(), min = *s.begin();
    if (k > min)
      return -1;
    else if (k == min)
      return n - 1;
    else
      return n;
  }
};
