class Solution {
public:
  string findDifferentBinaryString(vector<string> &nums) {
    set<string> seen(nums.begin(), nums.end());
    int n = nums.size();
    for (int mask = 0; mask < (1 << n); mask++) {
      string s(n, '0');
      for (int j = 0; j < n; j++)
        if (mask & (1 << j))
          s[j] = '1';
      if (seen.count(s) == 0)
        return s;
    }
    return string(n, '1');
  }
};
