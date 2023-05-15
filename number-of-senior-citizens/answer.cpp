class Solution {
public:
  int countSeniors(vector<string> &a) {
    int ans = 0;
    for (auto s : a) {
      int age = (s[11] - '0') * 10 + (s[12] - '0');
      if (age > 60)
        ans++;
    }
    return ans;
  }
};
