class Solution {
public:
  int minCharacters(string a, string b) {
    const int m = 26;
    int lena = a.size(), lenb = b.size();
    vector<int> cnta(m, 0), cntb(m, 0);
    for (char ch : a)
      cnta[ch - 'a']++;
    for (char ch : b)
      cntb[ch - 'a']++;

    int ans = INT_MAX;
    for (int i = 0; i < m; i++) {
      ans = min(ans, lena + lenb - cnta[i] - cntb[i]);
    }
    for (int i = 0; i + 1 < m; i++) {
      // a: [0, i]
      // b: [i + 1, m)
      int suma = accumulate(cnta.begin() + i + 1, cnta.end(), 0);
      int sumb = accumulate(cntb.begin(), cntb.begin() + i + 1, 0);
      ;
      ans = min(ans, suma + sumb);
      ans = min(ans, lena - suma + lenb - sumb);
    }
    return ans;
  }
};
