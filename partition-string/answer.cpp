class Solution {
public:
  vector<string> partitionString(string s) {
    int n = s.size();
    vector<string> ans;
    unordered_set<string> seen;
    for (int i = 0; i < n;) {
      string t(1, s[i]);
      int j = i + 1;
      while (j < n and seen.find(t) != seen.end())
        t.push_back(s[j++]);
      if (seen.find(t) == seen.end()) {
        seen.insert(t);
        ans.push_back(t);
      }
      i = j;
    }
    return ans;
  }
};
