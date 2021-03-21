class Solution {
public:
  int getNumberOfBacklogOrders(vector<vector<int>> &orders) {
    multiset<pair<int, long long>> buy, sell;
    for (auto &o : orders) {
      int p = o[0];
      long long n = o[1];
      if (o[2] == 0) {
        // buy
        while (!sell.empty() && n) {
          auto [price, amount] = *sell.begin();
          if (p < price)
            break;
          sell.erase(sell.begin());
          long long mn = min(n, amount);
          n -= mn;
          amount -= mn;
          if (amount)
            sell.insert({price, amount});
        }
        if (n)
          buy.insert({p, n});
      } else {
        // sell
        while (!buy.empty() && n) {
          auto it = prev(buy.end());
          auto [price, amount] = *it;
          if (p > price)
            break;
          buy.erase(it);
          long long mn = min(n, amount);
          n -= mn;
          amount -= mn;
          if (amount)
            buy.insert({price, amount});
        }
        if (n)
          sell.insert({p, n});
      }
    }

    const int MOD = 1e9 + 7;
    int ans = 0;
    for (auto &[k, v] : buy)
      ans = (ans + v) % MOD;
    for (auto &[k, v] : sell)
      ans = (ans + v) % MOD;
    return ans;
  }
};
