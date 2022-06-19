class Solution {
public:
  int minimumNumbers(int num, int k) {
    if (num == 0)
      return 0;

    vector<bool> vis(10, 0);
    int cnt = 0, mod = 0;
    while (true) {
      mod = (mod + k) % 10;
      if (vis[mod])
        break;
      cnt++;
      vis[mod] = 1;
      if (mod == num % 10)
        break;
    }

    if (!vis[num % 10] or num < cnt * k)
      return -1;
    return cnt;
  }
};
