using int64 = long long;

class Solution {
public:
  vector<long long> findXSum(vector<int> &a, int k, int x) {

    unordered_map<int, int> freq;      // value and it's frequency
    vector<set<pair<int, int>>> cs(2); // containers for pairs of <freq, value>
    vector<int64> sums(2, 0);          // sum for each container

    auto Change = [&](int val, int old_freq, int new_freq) {
      // Remove
      if (old_freq > 0) {
        int id = 0;
        if (cs[1].find({old_freq, val}) != cs[1].end())
          id = 1;

        auto it = cs[id].find({old_freq, val});
        cs[id].erase(it);
        sums[id] -= 1LL * val * old_freq;
      }

      // Add (always put in the samll container and then re-balance)
      if (new_freq > 0) {
        cs[0].insert({new_freq, val});
        sums[0] += 1LL * val * new_freq;
      }

      freq[val] = new_freq;
    };

    auto Balance = [&]() {
      // ensure big container's size firstly
      while (cs[0].size() + cs[1].size() >= x and cs[0].size() > 0 and
             cs[1].size() < x) {
        auto it = prev(cs[0].end());
        auto [f, val] = *it;
        cs[0].erase(it);
        sums[0] -= 1LL * f * val;

        cs[1].insert({f, val});
        sums[1] += 1LL * f * val;
      }

      // swap items
      while (cs[1].size() == x and cs[0].size() > 0) {
        auto it = prev(cs[0].end());
        auto [f0, val0] = *it;
        auto [f1, val1] = *cs[1].begin();

        if (f0 > f1 or (f0 == f1 and val0 > val1)) {
          cs[0].erase(it);
          cs[1].erase(cs[1].begin());

          sums[0] -= 1LL * f0 * val0;
          sums[1] -= 1LL * f1 * val1;

          cs[0].insert({f1, val1});
          cs[1].insert({f0, val0});

          sums[0] += 1LL * f1 * val1;
          sums[1] += 1LL * f0 * val0;
        } else {
          break;
        }
      }
    };

    int n = a.size();
    vector<int64> ans;
    for (int i = 0; i < n; i++) {
      // Add
      int old_freq = freq[a[i]];
      int new_freq = old_freq + 1;
      Change(a[i], old_freq, new_freq);

      // Remove
      if (i >= k) {
        old_freq = freq[a[i - k]];
        new_freq = old_freq - 1;
        Change(a[i - k], old_freq, new_freq);
      }

      // valid case
      if (i >= k - 1) {
        if (cs[0].size() + cs[1].size() >= x) {
          Balance();
          ans.push_back(sums[1]);
        } else {
          ans.push_back(sums[0] + sums[1]);
        }
      }
    }
    return ans;
  }
};
