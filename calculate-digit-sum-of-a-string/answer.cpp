class Solution {
public:
  string digitSum(string s, int k) {
    while (s.size() > k) {
      int m = 0, i = 0, n = s.size();
      string t;
      while (i < n) {
        int sum = 0;
        for (int j = 0; i < n and j < k; j++)
          sum += s[i++] - '0';
        t += to_string(sum);
      }
      s = t;
    }
    return s;
  }
};
