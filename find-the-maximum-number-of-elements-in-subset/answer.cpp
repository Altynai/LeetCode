using int64 = long long;

class Solution {
public:
  int maximumLength(vector<int> &a) {
    unordered_map<int64, int> freq;
    for (int x : a)
      freq[x]++;

    int ans = 1;
    if (freq[1] > 0)
      ans = max(ans, freq[1] % 2 == 0 ? freq[1] - 1 : freq[1]);

    int maxValue = *max_element(a.begin(), a.end());
    int m = (int)sqrt(maxValue);

    for (int i = 2; i <= m; i++) {
      int64 x = i;
      auto it = freq.find(x);
      if (it != freq.end() and it->second >= 2) {
        int cnt = 2;
        x *= x;
        while (freq.find(x) != freq.end() and freq[x] >= 1) {
          ans = max(ans, cnt + 1);
          if (freq[x] == 1)
            break;
          cnt += 2;
          x *= x;
        }
      }
    }
    return ans;
  }
};
