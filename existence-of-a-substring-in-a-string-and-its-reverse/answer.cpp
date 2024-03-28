class Solution {
public:
  bool isSubstringPresent(string s) {
    string t = s;
    reverse(t.begin(), t.end());

    int n = s.size();
    for (int i = 0; i + 1 < n; i++) {
      if (t.find(s.substr(i, 2)) != -1)
        return 1;
    }
    return 0;
  }
};
