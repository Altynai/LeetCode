using int64 = long long;

const int N = 26;

class Solution {
public:
  long long calculateScore(string s) {
    int n = s.size();
    int64 ans = 0;
    vector<vector<int>> pos(N);
    for (int i = 0; i < n; i++) {
      int mirror = N - 1 - (s[i] - 'a');
      if (pos[mirror].size() > 0) {
        int j = pos[mirror].back();
        pos[mirror].pop_back();
        ans += i - j;
      } else {
        pos[s[i] - 'a'].push_back(i);
      }
    }
    return ans;
  }
};
