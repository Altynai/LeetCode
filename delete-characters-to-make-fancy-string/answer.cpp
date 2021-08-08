class Solution {
public:
  string makeFancyString(string s) {
    vector<char> a;
    for (char ch : s) {
      a.push_back(ch);
      int n = a.size();
      if (n >= 3 && a[n - 1] == a[n - 2] && a[n - 2] == a[n - 3])
        a.pop_back();
    }
    return string(a.begin(), a.end());
  }
};
