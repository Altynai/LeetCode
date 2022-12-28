class Solution {
public:
  int closetTarget(vector<string> &words, string target, int startIndex) {
    int n = words.size(), ans = -1;
    for (int i = 0; i < n; i++) {
      if (words[i] == target) {
        int d = abs(i - startIndex);
        d = min(d, n - d);
        if (ans == -1 or d < ans)
          ans = d;
      }
    }
    return ans;
  }
};
