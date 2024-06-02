class Solution {
public:
  int minimumChairs(string s) {
    int cnt = 0, ans = 0;
    for (char ch : s) {
      if (ch == 'E') {
        cnt--;
        if (cnt < 0)
          ans = max(ans, -cnt);
      } else
        cnt++;
    }
    return ans;
  }
};
