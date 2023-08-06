using int64 = long long;

class Solution {
public:
  long long findMaximumElegance(vector<vector<int>> &items, int k) {
    int n = items.size();
    sort(items.begin(), items.end(), greater<>());

    unordered_map<int, int> categoryCnt;
    multiset<pair<int, int>> cand;
    int64 ans = 0;
    for (int i = 0; i < k; i++) {
      // we always keep the biggest profit among the same category
      // reset can be candidates for replacement
      if (++categoryCnt[items[i][1]] >= 2)
        cand.insert({items[i][0], items[i][1]});
      ans += items[i][0];
    }
    ans += 1LL * categoryCnt.size() * categoryCnt.size();

    int64 best = ans;
    for (int i = k; i < n; i++) {
      if (cand.empty())
        continue;

      // ignore item from the same category since we already sort by profit
      // decreasing order
      if (categoryCnt.count(items[i][1]))
        continue;

      // add a new category and replace a item with lowest profit
      auto [p, c] = *cand.begin();

      // remove lowest
      cand.erase(cand.begin());
      best -= p;
      best -= 1LL * categoryCnt.size() * categoryCnt.size();

      // replace with current item
      categoryCnt[items[i][1]]++;
      best += items[i][0];
      best += 1LL * categoryCnt.size() * categoryCnt.size();

      ans = max(ans, best);
    }
    return ans;
  }
};
