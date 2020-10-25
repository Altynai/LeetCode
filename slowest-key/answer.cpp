class Solution {
public:
  char slowestKey(vector<int> &releaseTimes, string keysPressed) {
    vector<int> cnt(26, 0);
    int n = releaseTimes.size();
    for (int i = 0; i < n; i++) {
      int j = keysPressed[i] - 'a';
      cnt[j] =
          max(cnt[j], releaseTimes[i] - (i == 0 ? 0 : releaseTimes[i - 1]));
    }
    int x = 0;
    for (int i = 1; i < 26; i++) {
      if (cnt[i] >= cnt[x])
        x = i;
    }
    return 'a' + x;
  }
};
