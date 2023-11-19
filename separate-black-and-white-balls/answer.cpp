using int64 = long long;

class Solution {
public:
  long long minimumSteps(string s) {
    int n = s.size();
    int64 ans = 0;
    for (int i = n - 1, j = n - 1; i >= 0; i--) {
      if (s[i] == '1') {
        ans += j - i;
        j--;
      }
    }
    return ans;
  }
};
