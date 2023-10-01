class Solution {
public:
  int minOperations(vector<int> &a, int k) {
    unordered_set<int> s;
    int n = a.size();
    for (int i = n - 1; i >= 0; i--) {
      if (a[i] <= k)
        s.insert(a[i]);
      if (s.size() == k)
        return n - i;
    }
    return -1;
  }
};
