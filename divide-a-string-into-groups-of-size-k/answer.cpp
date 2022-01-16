class Solution {
public:
  vector<string> divideString(string s, int k, char fill) {
    int n = s.size();
    vector<string> ans;
    for (int i = 0; i < n; i += k) {
      string t = s.substr(i, k);
      while (t.size() < k)
        t.push_back(fill);
      ans.push_back(t);
    }
    return ans;
  }
};
