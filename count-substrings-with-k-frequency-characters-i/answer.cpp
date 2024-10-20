const int N = 26;

class Solution {
public:
  int numberOfSubstrings(string s, int k) {
    int ans = 0, n = s.size();
    if (k == 1)
      return n * (n + 1) / 2;

    vector<int> freq(N, 0);
    for (int j = 0, i = 0; j < n; j++) {
      freq[s[j] - 'a']++;
      while (i < j and *max_element(freq.begin(), freq.end()) >= k)
        freq[s[i++] - 'a']--;
      ans += i;
    }
    return ans;
  }
};
