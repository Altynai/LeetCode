const int N = 26;
const int M = 8;

class Solution {
public:
  int minimumPushes(string s) {
    unordered_map<char, int> freq;
    for (char ch : s)
      freq[ch]++;

    vector<int> v;
    for (auto [_, cnt] : freq)
      v.push_back(cnt);
    sort(v.rbegin(), v.rend());

    int n = v.size(), ans = 0;
    vector<int> a(M, 0);
    for (int x : v) {
      int best = 0;
      for (int i = 1; i < M; i++) {
        if (a[i] < a[best])
          best = i;
      }
      ans += x * (a[best] + 1);
      a[best]++;
    }
    return ans;
  }
};
