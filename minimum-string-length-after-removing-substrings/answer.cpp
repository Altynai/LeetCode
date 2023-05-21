class Solution {
public:
  int minLength(string s) {
    vector<char> v;
    for (char c : s) {
      v.push_back(c);
      int n = v.size();
      if (n >= 2 and v[n - 2] == 'A' and v[n - 1] == 'B')
        v.pop_back(), v.pop_back();
      if (n >= 2 and v[n - 2] == 'C' and v[n - 1] == 'D')
        v.pop_back(), v.pop_back();
    }
    return v.size();
  }
};
