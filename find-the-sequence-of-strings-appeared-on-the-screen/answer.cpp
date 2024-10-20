class Solution {
public:
  vector<string> stringSequence(string s) {
    int n = s.size();
    vector<string> ans;
    string t;
    for (int i = 0; i < n; i++) {
      t.push_back('a');
      ans.push_back(t);
      for (int j = 1; j <= s[i] - 'a'; j++) {
        t.back()++;
        ans.push_back(t);
      }
    }
    return ans;
  }
};
