const int N = 26;

class Solution {
public:
  int maxDifference(string s) {
    vector<int> freq(N, 0);
    for (char c : s)
      freq[c - 'a']++;

    int odd = 0, even = INT_MAX;
    for (int x : freq) {
      if (x == 0)
        continue;
      if (x & 1)
        odd = max(odd, x);
      else
        even = min(even, x);
    }
    return odd - even;
  }
};
