const int N = 26;

class Solution {
public:
  int maximumLength(string s) {
    vector<vector<int>> lens(N);
    int n = s.size();
    for (int i = 0; i < n;) {
      int j = i, pos = s[i] - 'a';
      while (j < n and s[j] == s[i])
        j++;
      lens[pos].push_back(j - i);
      i = j;
    }

    int ans = -1;
    for (int i = 0; i < N; i++) {
      sort(lens[i].begin(), lens[i].end());
      int m = lens[i].size();

      // only pick from the largest one, e.g. 1 1 1 6
      if (m >= 1) {
        int len = lens[i][m - 1];
        if (len >= 3)
          ans = max(ans, len - 2);
      }

      // choose from the top 2
      if (m >= 2) {
        // e.g. 4 5
        if (lens[i][m - 1] > lens[i][m - 2])
          ans = max(ans, lens[i][m - 2]);
        // e.g. 2 2
        else if (lens[i][m - 2] > 1)
          ans = max(ans, lens[i][m - 2] - 1);
      }

      if (m >= 3)
        ans = max(ans, lens[i][m - 3]);
    }
    return ans;
  }
};
