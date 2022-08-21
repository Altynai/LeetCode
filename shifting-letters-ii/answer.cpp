class Solution {
public:
  string shiftingLetters(string s, vector<vector<int>> &shifts) {
    int n = s.size();
    vector<int> sum(n + 1, 0);
    for (auto &shift : shifts) {
      int val = (shift[2] ? 1 : 25);
      sum[shift[0]] += val;
      sum[shift[1] + 1] -= val;
    }

    for (int i = 0; i < n; i++) {
      if (i > 0)
        sum[i] += sum[i - 1];
      int x = (sum[i] % 26 + 26) % 26;
      int y = (s[i] - 'a' + x) % 26;
      s[i] = 'a' + y;
    }
    return s;
  }
};
