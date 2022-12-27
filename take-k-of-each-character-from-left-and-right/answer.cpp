class Solution {
public:
  int takeCharacters(string s, int k) {
    vector<int> freq(3, 0);
    for (char ch : s)
      freq[ch - 'a']++;

    for (int i = 0; i < 3; i++) {
      freq[i] -= k;
      if (freq[i] < 0)
        return -1;
    }

    vector<int> cnt(3, 0);
    int len = 0, n = s.size();
    for (int i = 0, j = 0; j < n; j++) {
      int idx = s[j] - 'a';
      cnt[idx]++;
      while (i <= j and cnt[idx] > freq[idx]) {
        cnt[s[i] - 'a']--;
        i++;
      }
      len = max(len, j - i + 1);
    }
    return n - len;
  }
};
