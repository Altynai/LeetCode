class Solution {
public:
  string removeStars(string s) {
    vector<char> a;
    for (char ch : s) {
      if (ch != '*')
        a.push_back(ch);
      else if (a.size())
        a.pop_back();
    }
    return string(a.begin(), a.end());
  }
};
