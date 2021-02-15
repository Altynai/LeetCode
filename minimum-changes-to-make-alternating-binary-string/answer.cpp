class Solution {
public:
  int minOperations(string s) {
    int ans = s.size();
    for (char a : "01") {
      int cnt = 0;
      for (char b : s) {
        if (a != b)
          cnt++;
        a ^= 1;
      }
      ans = min(ans, cnt);
    }
    return ans;
  }
};
