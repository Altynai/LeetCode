using int64 = long long;

#define bitCount(n) __builtin_popcountll((n))

const int N = 26;

class Solution {
public:
  int maxPartitionsAfterOperations(string s, int k) {
    int n = s.size();
    unordered_map<int64, int> cache;

    function<int(int, int, bool)> dfs = [&](int pos, int state,
                                            bool can_change) -> int {
      if (pos == n)
        return 1;

      int64 key = ((1LL * pos) << 27) | (state << 1) | can_change;
      auto it = cache.find(key);
      if (it != cache.end())
        return it->second;

      int current_idx = s[pos] - 'a';
      int best = 0;

      // don't change
      int new_state = state | (1 << current_idx);
      if (bitCount(new_state) > k) {
        best = 1 + dfs(pos + 1, 1 << current_idx, can_change);
      } else {
        best = dfs(pos + 1, new_state, can_change);
      }

      // change
      if (can_change) {
        for (int i = 0; i < N; i++) {
          if (i == current_idx)
            continue;

          new_state = state | (1 << i);
          if (bitCount(new_state) > k) {
            best = max(best, 1 + dfs(pos + 1, 1 << i, false));
          } else {
            best = max(best, dfs(pos + 1, new_state, false));
          }
        }
      }

      return cache[key] = best;
    };

    return dfs(0, 0, true);
  }
};
