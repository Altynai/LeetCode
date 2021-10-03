class Solution {
public:
  int waysToPartition(vector<int> &a, int k) {
    int n = a.size();
    int ans = 0;

    long long sum = 0;
    unordered_map<long long, vector<int>> sfx;
    for (int i = n - 1; i >= 0; i--) {
      sum += a[i];
      // index 0 is not valid pivot
      if (i >= 1)
        sfx[sum].push_back(i);
    }
    long long total = sum;

    vector<long long> pfxSum(n, 0);
    unordered_map<long long, vector<int>> pfx;
    sum = 0;
    for (int i = 0; i < n; i++) {
      sum += a[i];
      pfxSum[i] = sum;
      pfx[sum].push_back(i);
    }

    for (auto &[k, v] : pfx)
      sort(v.begin(), v.end());
    for (auto &[k, v] : sfx)
      sort(v.begin(), v.end());

    auto countpfx = [&](long long key, int r) -> int {
      auto it = pfx.find(key);
      if (it == pfx.end())
        return 0;

      // count # <= r
      vector<int> &p = it->second;
      return lower_bound(p.begin(), p.end(), r + 1) - p.begin();
    };

    auto countsfx = [&](long long key, int l) -> int {
      auto it = sfx.find(key);
      if (it == sfx.end())
        return 0;

      // count # >= l
      vector<int> &p = it->second;
      return p.end() - lower_bound(p.begin(), p.end(), l);
    };

    for (int i = 0; i < n; i++) {
      // no change
      if (sum % 2 == 0) {
        long long half = total / 2;
        if (i)
          ans = max(ans, countsfx(half, i));
      }

      // change to k
      long long sum2 = total - a[i] + k;
      if (sum2 % 2 == 0) {
        long long half = sum2 / 2;
        // count # of second half starting from position i + 1
        int c = countsfx(half, i + 1);
        if (i >= 1) {
          // count # of first half starting, this includes i as pivot as well
          c += countpfx(half, i - 1);
        }
        ans = max(ans, c);
      }
    }
    return ans;
  }
};
