class Solution {
public:
  int minTimeToType(string word) {
    char c = 'a';
    int ans = 0;
    for (char p : word) {
      ans += min(abs(c - p), 26 - abs(c - p)) + 1;
      c = p;
    }
    return ans;
  }
};
