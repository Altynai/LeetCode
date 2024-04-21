const int N = 26;

class Solution {
public:
  int numberOfSpecialChars(string s) {
    int n = s.size();
    vector<int> last(N, -1), first(N, -1);
    for (int i = 0; i < n; i++) {
      if (islower(s[i])) {
        int idx = s[i] - 'a';
        last[idx] = i;
      } else {
        int idx = s[i] - 'A';
        if (first[idx] == -1)
          first[idx] = i;
      }
    }

    int ans = 0;
    for (int i = 0; i < N; i++) {
      if (first[i] == -1 or last[i] == -1)
        continue;
      if (last[i] < first[i])
        ans++;
    }
    return ans;
  }
};
