class Solution {
public:
  int countPairs(vector<int> &a) {
    int n = a.size();
    int ans = 0;
    unordered_map<string, int> freq;
    unordered_set<string> candidates;

    function<void(int, string &)> dfs = [&](int d, string &s) {
      if (d == 2) {
        candidates.insert(s);
        return;
      }

      int m = s.size();
      for (int i = 0; i < m; i++) {
        for (int j = 0; j < i; j++) {
          swap(s[i], s[j]);
          candidates.insert(s);
          dfs(d + 1, s);
          swap(s[i], s[j]);
        }
      }
    };

    string s = to_string(*max_element(a.begin(), a.end()));
    for (int i = 0; i < n; i++) {
      fill(s.begin(), s.end(), '0');
      for (int x = a[i], j = s.size() - 1; x > 0; x /= 10, j--)
        s[j] = '0' + (x % 10);

      candidates.clear();
      candidates.insert(s);
      dfs(0, s);

      for (string t : candidates) {
        auto it = freq.find(t);
        if (it != freq.end())
          ans += it->second;
      }
      freq[s]++;
    }
    return ans;
  }
};
