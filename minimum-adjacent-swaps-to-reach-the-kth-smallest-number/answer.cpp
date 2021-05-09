class Solution {
public:
  int getMinSwaps(string s, int k) {
    string t = s;
    while (k--)
      next_permutation(t.begin(), t.end());

    int ans = 0;
    int n = s.size();
    for (int i = 0; i < n; i++) {
      if (s[i] == t[i])
        continue;
      int j = i;
      while (j < n && s[j] != t[i])
        j++;
      assert(j < n);

      int x = j;
      while (x >= i + 1) {
        swap(s[x], s[x - 1]);
        x--;
        ans++;
      }
    }
    return ans;
  }
};
