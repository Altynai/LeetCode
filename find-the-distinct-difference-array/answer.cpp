class Solution {
public:
  vector<int> distinctDifferenceArray(vector<int> &a) {
    int n = a.size();
    vector<int> ans(n);
    for (int i = n - 1; i >= 0; i--) {
      set<int> left(a.begin(), a.begin() + i + 1);
      set<int> right(a.begin() + i + 1, a.begin() + n);
      ans[i] = left.size() - right.size();
    }
    return ans;
  }
};
