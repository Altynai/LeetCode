class Solution {
public:
  string compressedString(string s) {
    string ans;
    int n = s.size();
    for (int i = 0; i < n;) {
      int j = i + 1;
      while (j < n and s[j] == s[i] and j - i + 1 <= 9)
        j++;
      ans.push_back('0' + (j - i));
      ans.push_back(s[i]);
      i = j;
    }
    return ans;
  }
};
