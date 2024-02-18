const int N = 26;

class Solution {
public:
  string lastNonEmptyString(string s) {
    int n = s.size();
    vector<int> cnt(N, 0), last(N, -1);
    for (int i = 0; i < n; i++) {
      ++cnt[s[i] - 'a'];
      last[s[i] - 'a'] = i;
    }

    int freq = *max_element(cnt.begin(), cnt.end());
    vector<pair<int, int>> v;
    for (int i = 0; i < N; i++) {
      if (cnt[i] == freq) {
        v.push_back({last[i], i});
      }
    }

    sort(v.begin(), v.end());
    string ans = "";
    for (auto [i, j] : v) {
      ans.push_back('a' + j);
    }
    return ans;
  }
};
