using int64 = long long;

class Solution {
public:
  long long minimumCost(vector<int> &a, int k, int dist) {
    int n = a.size();

    // i: start index of second subarray
    // j: start index of k-th subarray
    // j <= i + dist
    // ans = a[0] + a[i] + func(a[i + 1 .... j], k - 2)
    // func: choose k - 2 minimal elements from the subarray (maintained by 2
    // sets)

    multiset<int> small, big;
    int64 sum = 0;

    auto Balance = [&]() {
      // big -> small
      while (!big.empty() and small.size() < k - 2) {
        int y = *big.begin();
        big.erase(big.begin());
        small.insert(y), sum += y;
      }

      // small -> big
      while (small.size() > k - 2) {
        auto it = prev(small.end());
        int x = *it;
        small.erase(it), sum -= x;
        big.insert(x);
      }

      // swap
      while (!small.empty() and !big.empty() and
             *big.begin() < *prev(small.end())) {
        auto it = prev(small.end());
        int x = *it;
        small.erase(it), sum -= x;

        int y = *big.begin();
        big.erase(big.begin());

        small.insert(y), sum += y;
        big.insert(x);
      }
    };

    auto Add = [&](int x) {
      if (small.size() < k - 2)
        small.insert(x), sum += x;
      else
        big.insert(x);
      Balance();
    };

    auto Delete = [&](int x) {
      auto it = big.find(x);
      if (it != big.end())
        big.erase(it);
      else
        small.erase(small.find(x)), sum -= x;
      Balance();
    };

    int64 ans = LLONG_MAX;
    for (int i = 1, l = 2, r = 2; i < n; i++) {
      // keep l and r in range [i + 1, i + dist]
      while (l < n and l < i + 1)
        Delete(a[l++]);
      while (r < n and r <= i + dist)
        Add(a[r++]);
      if (small.size() == k - 2)
        ans = min(ans, sum + a[0] + a[i]);
    }
    return ans;
  }
};
