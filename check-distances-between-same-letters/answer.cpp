const int N = 26;

class Solution {
public:
  bool checkDistances(string s, vector<int> &d) {
    vector<int> p(N, -1);
    int n = s.size();
    for (int i = 0; i < n; i++) {
      int k = s[i] - 'a';
      if (p[k] != -1 and d[k] != i - p[k] - 1)
        return 0;
      p[k] = i;
    }
    return 1;
  }
};
