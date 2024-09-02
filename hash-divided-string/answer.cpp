class Solution {
public:
  string stringHash(string s, int k) {
    string ans;
    int n = s.size();
    for (int i = 0; i < n / k; i++) {
      int sum = 0;
      for (int j = i * k; j < (i + 1) * k; j++)
        sum += s[j] - 'a';
      ans.push_back('a' + (sum % 26));
    }
    return ans;
  }
};
