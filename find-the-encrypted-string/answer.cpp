class Solution {
public:
  string getEncryptedString(string s, int k) {
    int n = s.size();
    k %= n;
    return s.substr(k) + s.substr(0, k);
  }
};
