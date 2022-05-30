const int N = 26;

class Solution {
public:
  int rearrangeCharacters(string s, string target) {
    vector<int> x(N, 0), y(N, 0);
    for (char ch : s)
      x[ch - 'a']++;
    for (char ch : target)
      y[ch - 'a']++;

    int ans = INT_MAX;
    for (int i = 0; i < N; i++)
      if (y[i] > 0)
        ans = min(ans, x[i] / y[i]);
    return ans;
  }
};
