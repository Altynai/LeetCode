const int N = 26;

class Solution {
public:
  int maxPalindromesAfterOperations(vector<string> &words) {
    int n = words.size();
    vector<int> cnt(N, 0), lens;
    for (string word : words) {
      lens.push_back(word.size());
      for (char ch : word)
        cnt[ch - 'a']++;
    }

    int ans = 0, pairs = 0;
    for (int i = 0; i < N; i++)
      pairs += cnt[i] / 2;

    sort(lens.begin(), lens.end());
    for (int len : lens) {
      pairs -= len / 2;
      if (pairs >= 0)
        ans++;
    }
    return ans;
  }
};
