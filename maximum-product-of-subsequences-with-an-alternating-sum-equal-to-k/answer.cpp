using State = array<int, 5>; // index, product, sum, sign, taken

// Custom hash function for array<int, 5>
struct ArrayHasher {
  std::size_t operator()(const std::array<int, 5> &arr) const {
    std::size_t seed = 0;
    for (const int &i : arr) {
      // Combine the hash of the current element with the running hash value
      seed ^= std::hash<int>{}(i) + 0x9e3779b9 + (seed << 6) + (seed >> 2);
    }
    return seed;
  }
};

class Solution {
private:
  unordered_map<State, int, ArrayHasher> dp;

public:
  int maxProduct(vector<int> &a, int k, int limit) {
    int n = a.size(), sum = 0;
    for (int x : a)
      sum += x;
    if (sum < abs(k))
      return -1;

    dp.clear();

    function<int(int, int, int, int, int)> dfs =
        [&](int i, int p, int sum, int sign, int taken) -> int {
      if (i == n) {
        if (taken > 0 and sum == k and p <= limit)
          return p;
        return -1;
      }

      array<int, 5> key = {i, p, sum, sign, taken};
      auto it = dp.find(key);
      if (it != dp.end())
        return it->second;

      int p2 = (p * a[i] > limit) ? limit + 1 : p * a[i];
      int take = dfs(i + 1, p2, sum + sign * a[i], sign * -1, 1);
      int skip = dfs(i + 1, p, sum, sign, taken);
      return dp[key] = max(take, skip);
    };

    return dfs(0, 1, 0, +1, 0);
  }
};
