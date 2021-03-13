class Solution {
public:
  bool checkOnesSegment(string s) {
    int n = s.size(), cnt = 0;
    for (int i = 0; i < n;) {
      if (s[i] == '0')
        i++;
      else {
        if (++cnt > 1)
          return 0;
        while (i < n && s[i] == '1')
          i++;
      }
    }
    return 1;
  }
};
