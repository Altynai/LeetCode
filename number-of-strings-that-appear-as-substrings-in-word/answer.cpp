class Solution {
public:
  int numOfStrings(vector<string> &patterns, string word) {
    int cnt = 0;
    for (auto &s : patterns)
      if (word.find(s) != -1)
        cnt++;
    return cnt;
  }
};
