class Solution {
public:
  string generateString(string str1, string str2) {
    int n = str1.size(), m = str2.size();
    string ans(n + m - 1, '*');
    vector<bool> fixed(n + m - 1, 0);
    for (int i = 0; i < n; i++) {
      if (str1[i] == 'T') {
        for (int j = 0; j < m; j++) {
          int k = i + j;
          if (fixed[k] and ans[k] != str2[j])
            return "";
          fixed[k] = 1;
          ans[k] = str2[j];
        }
      }
    }

    for (int i = 0; i < n + m - 1; i++) {
      if (!fixed[i])
        ans[i] = 'a';
    }

    for (int i = 0; i < n; i++) {
      if (str1[i] == 'F') {
        bool matched = 1;
        for (int j = 0; matched and j < m; j++) {
          if (ans[i + j] != str2[j])
            matched = 0;
        }
        if (!matched)
          continue;

        // find the right most non-fixed position and set to 'b'
        int pos = -1;
        for (int j = 0; j < m; j++) {
          if (!fixed[i + j])
            pos = i + j;
        }
        if (pos == -1)
          return "";
        ans[pos] = 'b';
      }
    }
    return ans;
  }
};
