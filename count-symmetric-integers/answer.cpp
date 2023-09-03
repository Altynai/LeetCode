class Solution {
public:
  int countSymmetricIntegers(int low, int high) {
    int ans = 0;
    for (int i = low; i <= high; i++) {
      string s = to_string(i);
      int n = s.size();

      if (n & 1)
        continue;
      int sum = 0, half = 0;
      for (int j = 0; j < n; j++) {
        sum += s[j] - '0';
        if (j < n / 2)
          half += s[j] - '0';
      }
      if (sum - half == half)
        ans++;
    }
    return ans;
  }
};
