class Solution {
public:
  vector<int> lastVisitedIntegers(vector<string> &words) {
    vector<int> s, ans;
    int k = -1;
    for (string word : words) {
      if (word == "prev") {
        k++;
        int n = s.size();
        ans.push_back(n - 1 - k >= 0 ? s[n - 1 - k] : -1);
      } else {
        k = -1;
        s.push_back(stoi(word));
      }
    }
    return ans;
  }
};
