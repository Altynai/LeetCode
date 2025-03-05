class Solution {
public:
  vector<int> transformArray(vector<int> &a) {
    for (int &x : a)
      x %= 2;
    sort(a.begin(), a.end());
    return a;
  }
};
