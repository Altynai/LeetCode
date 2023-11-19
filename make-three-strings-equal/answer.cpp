class Solution {
public:
  int findMinimumOperations(string s1, string s2, string s3) {
    int n = min(min(s1.size(), s2.size()), s3.size());
    int p = -1;
    for (int i = 0; i < n; i++) {
      if (s1[i] != s2[i] or s2[i] != s3[i])
        break;
      p = i;
    }
    if (p < 1)
      return -1;
    return s1.size() + s2.size() + s3.size() - (p + 1) * 3;
  }
};

