class Solution {
public:
  int maxHappyGroups(int B, vector<int> &a) {
    vector<int> cnt(B, 0);
    int ans = 0;
    for (int num : a) {
      if (num % B == 0)
        ans++;
      else if (cnt[B - num % B]) {
        ans++;
        cnt[B - num % B]--;
      } else {
        cnt[num % B]++;
      }
    }

    using Key = pair<int, vector<int>>;
    map<Key, int> cache;

    function<int(int, vector<int>)> dfs = [&](int remain,
                                              vector<int> cur) -> int {
      Key key = {remain, cur};
      if (cache.count(key))
        return cache[key];

      if (accumulate(cur.begin(), cur.end(), 0) == 0)
        return cache[key] = 0;

      int ret = 0;
      for (int i = 1; i < B; i++) {
        if (cur[i] == 0)
          continue;
        vector<int> nxt = cur;
        nxt[i]--;
        int remain2 = (remain - i + B) % B;
        ret = max(ret, dfs(remain2, nxt));
      }
      if (remain == 0)
        ret++;
      return cache[key] = ret;
    };

    return ans + dfs(0, cnt);
  }
};
