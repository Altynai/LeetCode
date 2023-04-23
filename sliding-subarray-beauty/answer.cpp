class Solution {
public:
  vector<int> getSubarrayBeauty(vector<int> &a, int k, int x) {
    int n = a.size();

    multiset<int> neg, other;

    auto Maintain = [&]() {
      // neg <- other
      while (neg.size() < x and !other.empty() and *other.begin() < 0) {
        neg.insert(*other.begin());
        other.erase(other.begin());
      }

      // swap
      while (!neg.empty() and !other.empty() and
             *other.begin() < *prev(neg.end())) {
        auto pit = prev(neg.end()), qit = other.begin();
        int p = *pit, q = *qit;

        neg.erase(pit);
        other.erase(qit);

        neg.insert(q);
        other.insert(p);
      }

      while (neg.size() > x) {
        auto it = prev(neg.end());
        other.insert(*it);
        neg.erase(it);
      }
    };

    auto Add = [&](int val) {
      if (val >= 0)
        other.insert(val);
      else
        neg.insert(val);
      Maintain();
    };

    auto Remove = [&](int val) {
      auto it = neg.find(val);
      if (it != neg.end())
        neg.erase(it);
      else
        other.erase(other.find(val));
      Maintain();
    };

    for (int i = 0; i < k - 1; i++)
      Add(a[i]);

    vector<int> ans(n - k + 1, 0);
    for (int i = k - 1; i < n; i++) {
      Add(a[i]);
      if (neg.size() == x)
        ans[i - (k - 1)] = *prev(neg.end());
      Remove(a[i - (k - 1)]);
    }
    return ans;
  }
};
