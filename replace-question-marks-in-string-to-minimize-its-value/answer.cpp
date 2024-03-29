const int N = 26;

template <typename T>
using min_priority_queue = priority_queue<T, vector<T>, greater<T>>;

class Solution {
public:
  string minimizeStringValue(string s) {
    int n = s.size();
    vector<int> cnt(N, 0);
    for (int i = 0; i < n; i++) {
      if (s[i] != '?')
        cnt[s[i] - 'a']++;
    }

    min_priority_queue<pair<int, int>> que;
    for (int i = 0; i < N; i++)
      que.push({cnt[i], i});

    vector<int> ans;
    for (int i = 0; i < n; i++) {
      if (s[i] == '?') {
        int j = que.top().second;
        ans.push_back(j);
        que.pop();
        que.push({++cnt[j], j});
      }
    }

    sort(ans.begin(), ans.end());
    for (int i = 0, j = 0; i < n; i++) {
      if (s[i] == '?')
        s[i] = 'a' + ans[j++];
    }
    return s;
  }
};
