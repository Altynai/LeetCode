class Solution {
public:
  int countWords(vector<string> &a, vector<string> &b) {
    map<string, int> cntA, cntB;
    for (string &s : a)
      cntA[s]++;
    for (string &s : b)
      cntB[s]++;
    int ans = 0;
    for (auto &[s, cnt] : cntA) {
      if (cnt == 1 && cntB[s] == 1)
        ans++;
    }
    return ans;
  }
};
