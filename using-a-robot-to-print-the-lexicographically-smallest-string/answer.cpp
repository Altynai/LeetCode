const int N = 26;

class Solution {
public:
  string robotWithString(string s) {
    int n = s.size();
    vector<int> cnt(N, 0);
    for (char c : s)
      cnt[c - 'a']++;

    string t;
    stack<char> stk;
    for (int i = 0, j = 0; i < N; i++) {
      while (stk.size() and stk.top() - 'a' <= i) {
        t.push_back(stk.top());
        stk.pop();
      }

      while (j < n and cnt[i] > 0) {
        if (s[j] - 'a' == i)
          t.push_back(s[j]);
        else
          stk.push(s[j]);
        cnt[s[j] - 'a']--;
        j++;
      }
    }
    return t;
  }
};
