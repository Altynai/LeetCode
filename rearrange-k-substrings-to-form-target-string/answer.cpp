class Solution {
public:
  bool isPossibleToRearrange(string s, string t, int k) {
    int n = s.size();
    int len = n / k;
    unordered_map<string, int> freq;
    for (int i = 0; i < k; i++)
      freq[s.substr(i * len, len)]++;

    for (int i = 0; i < k; i++) {
      string sb = t.substr(i * len, len);
      auto it = freq.find(sb);
      if (it != freq.end() and it->second > 0)
        it->second--;
      else
        return 0;
    }
    return 1;
  }
};
