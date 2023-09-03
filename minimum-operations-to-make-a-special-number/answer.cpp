class Solution {
public:
  int minimumOperations(string s) {
    int n = s.size();
    int ans = n;

    // ends with 25, 75
    for (int x : {2, 7}) {
      int i = n - 1;
      while (i >= 0 and s[i] != '5')
        i--;
      if (i < 0)
        continue;

      while (i >= 0 and s[i] - '0' != x)
        i--;
      if (i >= 0)
        ans = min(ans, n - i - 2);
    }

    // ends with 50
    int i = n - 1;
    while (i >= 0 and s[i] != '0')
      i--;
    if (i >= 0) {
      i--;
      while (i >= 0 and s[i] != '5')
        i--;
      if (i >= 0)
        ans = min(ans, n - i - 2);
    }

    // ends with ?00
    i = n - 1;
    while (i >= 0 and s[i] != '0')
      i--;
    if (i >= 0) {
      i--;
      while (i >= 0 and s[i] != '0')
        i--;
      if (i > 0)
        ans = min(ans, n - i - 2);
    }

    // make it to zero
    if (s.find('0') != -1)
      ans = min(ans, n - 1);
    return ans;
  }
};
