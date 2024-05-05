class Solution {
public:
  int minimumOperationsToMakeKPeriodic(string s, int k) {
    int n = s.size();
    unordered_map<string, int> freq;
    int cnt = 0;
    for (int i = 0; i < n; i += k)
      cnt = max(cnt, ++freq[s.substr(i, k)]);
    return n / k - cnt;
  }
};
