class Solution {
public:
  string decodeCiphertext(string s, int r) {
    int c = s.size() / r;
    vector<char> ans;
    for (int j = 0; j < c; j++) {
      for (int i = 0, k = j; i < r && k < c; i++, k++)
        ans.push_back(s[i * c + k]);
    }
    while (ans.size() && ans.back() == ' ')
      ans.pop_back();
    return string(ans.begin(), ans.end());
  }
};
