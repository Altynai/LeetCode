class Solution {
public:
  string maximumBinaryString(string s) {
    int n = s.size();
    if (n == 1)
      return s;

    int i = s.find_first_of('0');
    if (i == -1)
      return s;

    vector<int> cnt(2, 0);
    for (int j = i; j < n; j++)
      cnt[s[j] - '0']++;

    int j = i;
    while (cnt[0]-- > 1)
      s[j++] = '1';
    s[j++] = '0';
    while (cnt[1]--)
      s[j++] = '1';
    return s;
  }
};
