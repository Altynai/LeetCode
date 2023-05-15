class Solution {
public:
  bool doesValidArrayExist(vector<int> &a) {
    int n = a.size();
    for (int i = 0; i <= 1; i++) {
      int x = i;
      for (int j = 1; j < n; j++)
        x ^= a[j - 1];
      if ((x ^ i) == a[n - 1])
        return 1;
    }
    return 0;
  }
};
