const int N = 26;

class Solution {
public:
  int findPermutationDifference(string s, string t) {
    int n = s.size();
    vector<int> where(N, -1);
    for (int i = 0; i < n; i++)
      where[s[i] - 'a'] = i;
    int ans = 0;
    for (int i = 0; i < n; i++)
      ans += abs(i - where[t[i] - 'a']);
    return ans;
  }
};
