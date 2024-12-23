class Solution {
public:
  int minimumOperations(vector<int> &a) {
    int ans = 0;
    while (a.size() != unordered_set<int>(a.begin(), a.end()).size()) {
      if (a.size() < 3)
        a.clear();
      else
        a = vector<int>(a.begin() + 3, a.end());
      ans++;
    }
    return ans;
  }
};
