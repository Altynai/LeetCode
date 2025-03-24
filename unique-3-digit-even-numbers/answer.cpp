const int N = 10;

class Solution {
public:
  int totalNumbers(vector<int> &digits) {
    vector<int> freq(N, 0);
    for (int x : digits)
      freq[x]++;

    int ans = 0;
    for (int i = 100; i <= 998; i += 2) {
      vector<int> f = freq;
      for (int x = i; x > 0; x /= N)
        f[x % N]--;
      if (*min_element(f.begin(), f.end()) >= 0)
        ans++;
    }
    return ans;
  }
};
