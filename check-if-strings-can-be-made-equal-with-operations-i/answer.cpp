class Solution {
public:
  bool canBeEqual(string s1, string s2) {
    for (int i = 0; i <= 1; i++) {
      if (min(s1[i], s1[i + 2]) != min(s2[i], s2[i + 2]) or
          max(s1[i], s1[i + 2]) != max(s2[i], s2[i + 2]))
        return 0;
    }
    return 1;
  }
};
