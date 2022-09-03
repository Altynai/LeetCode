class Solution {
public:
  bool findSubarrays(vector<int> &a) {
    int n = a.size();
    set<int> seen;
    for (int i = 0; i + 1 < n; i++) {
      int x = a[i] + a[i + 1];
      if (seen.count(x))
        return true;
      seen.insert(x);
    }
    return false;
  }
};
