class Solution {
public:
  int minimumDeletions(string s) {
    int a = 0, b = 0;
    for (char ch : s) {
      if (ch == 'a')
        a++;
      else
        b = max(a, b) + 1;
    }
    return s.size() - max(a, b);
  }
};
