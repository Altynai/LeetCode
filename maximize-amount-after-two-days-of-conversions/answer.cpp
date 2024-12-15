template <class T> bool umax(T &a, const T b) { return a < b ? a = b, 1 : 0; }

class Solution {
private:
  map<pair<string, string>, double> floyd(vector<vector<string>> &pairs,
                                          vector<double> &rates) {
    unordered_set<string> currencies;
    map<pair<string, string>, double> res;
    int n = pairs.size();
    for (int i = 0; i < n; i++) {
      vector<string> p = pairs[i];
      currencies.insert(p[0]);
      currencies.insert(p[1]);
      res[{p[0], p[1]}] = rates[i];
      res[{p[1], p[0]}] = 1.0 / rates[i];
    }

    for (auto k : currencies) {
      for (auto i : currencies) {
        for (auto j : currencies) {
          if (res.count({i, k}) == 0)
            continue;
          if (res.count({k, j}) == 0)
            continue;
          umax(res[{i, j}], res[{i, k}] * res[{k, j}]);
        }
      }
    }
    return res;
  }

public:
  double maxAmount(string initialCurrency, vector<vector<string>> &pairs1,
                   vector<double> &rates1, vector<vector<string>> &pairs2,
                   vector<double> &rates2) {
    auto graph1 = floyd(pairs1, rates1);
    auto graph2 = floyd(pairs2, rates2);
    double ans = 1.0;
    for (auto [edge, rate] : graph1) {
      if (edge.first == initialCurrency) {
        // day 1 & 2
        auto it = graph2.find({edge.second, initialCurrency});
        if (it != graph2.end())
          umax(ans, rate * it->second);
      }
    }
    return ans;
  }
};
