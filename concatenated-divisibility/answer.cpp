#define bit(n, i) (((n) >> (i)) & 1)

class Solution {
public:
  vector<int> concatenatedDivisibility(vector<int> &a, int k) {
    int n = a.size();
    sort(a.begin(), a.end());

    // dp[mask][i][mod]
    // we should scan from the end, so next j will be place in front
    // next number in new state will be "a[j]a[i]....."
    // and we will choose the smallest a[j] if possible

    vector<int> lens(1 << n, 0);
    for (int mask = 1; mask < (1 << n); mask++) {
      for (int i = 0; i < n; i++) {
        if (bit(mask, i) == 0)
          continue;
        string s = to_string(a[i]);
        lens[mask] += s.size();
      }
    }

    int MAX_LEN = lens[(1 << n) - 1];
    vector<int> mod10(MAX_LEN, 1 % k);
    for (int i = 1; i < MAX_LEN; i++)
      mod10[i] = mod10[i - 1] * 10 % k;

    using State = array<int, 3>; // mask, index, mod
    auto Update = [&](State &lhs, State rhs) {
      if (lhs[0] == -1)
        lhs = rhs;
      else if (rhs[1] < lhs[1])
        lhs = rhs;
    };

    vector<vector<vector<bool>>> dp(
        1 << n, vector<vector<bool>>(n, vector<bool>(k, 0)));
    vector<vector<vector<State>>> pv(
        1 << n, vector<vector<State>>(n, vector<State>(k, {-1, -1, -1})));
    for (int i = 0; i < n; i++)
      dp[1 << i][i][a[i] % k] = 1;
    for (int mask = 1; mask < (1 << n); mask++) {
      for (int last = 0; last < n; last++) {
        if (bit(mask, last) == 0)
          continue;
        for (int mod = 0; mod < k; mod++) {
          if (!dp[mask][last][mod])
            continue;

          for (int i = 0; i < n; i++) {
            if (bit(mask, i))
              continue;

            int mod2 = (mod10[lens[mask]] * a[i] + mod) % k;
            dp[mask | (1 << i)][i][mod2] = 1;
            Update(pv[mask | (1 << i)][i][mod2], {mask, last, mod});
          }
        }
      }
    }

    int last = -1;
    for (int i = 0; i < n; i++) {
      if (dp[(1 << n) - 1][i][0]) {
        last = i;
        break;
      }
    }
    if (last == -1)
      return {};

    vector<int> ans;
    for (int mask = (1 << n) - 1, mod = 0; last != -1;) {
      ans.push_back(a[last]);
      State nxt = pv[mask][last][mod];
      mask = nxt[0], last = nxt[1], mod = nxt[2];
    }
    return ans;
  }
};
