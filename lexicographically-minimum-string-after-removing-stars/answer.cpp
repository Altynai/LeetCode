const int N = 26;

class Solution {
public:
  string clearStars(string s) {
    int n = s.size();
    vector<bool> vis(n, 0);
    vector<set<int>> pos(N);
    for (int i = 0; i < n; i++) {
      if (s[i] == '*') {
        vis[i] = 1;
        for (int j = 0; j < N; j++) {
          auto it = pos[j].lower_bound(i);
          if (it != pos[j].begin()) {
            it = prev(it);
            vis[*it] = 1;
            pos[j].erase(it);
            break;
          }
        }
      } else {
        int k = s[i] - 'a';
        pos[k].insert(i);
      }
    }

    string ans;
    for (int i = 0; i < n; i++) {
      if (!vis[i])
        ans.push_back(s[i]);
    }
    return ans;
  }
};
