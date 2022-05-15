class Solution {
public:
  vector<string> removeAnagrams(vector<string> &words) {
    vector<string> ans;
    for (auto w : words) {
      if (ans.empty())
        ans.push_back(w);
      else {
        string a = ans.back(), b = w;
        sort(a.begin(), a.end());
        sort(b.begin(), b.end());
        if (a != b)
          ans.push_back(w);
      }
    }
    return ans;
  }
};
