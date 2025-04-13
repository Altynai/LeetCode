using int64 = long long;

class Solution {
public:
  int minimumPairRemoval(vector<int> &nums) {
    int n = nums.size();

    map<int, int64> vals;       // index, value
    unordered_set<int> indices; // bad indices shall be removed
    set<pair<int64, int>> sums; // sum, index

    for (int i = 0; i < n; i++) {
      vals[i] = nums[i];
      if (i + 1 < n) {
        sums.insert({nums[i] + nums[i + 1], i});
        if (nums[i] > nums[i + 1])
          indices.insert(i);
      }
    }

    // index: i, j, k, l
    // vals : w, x, y, z
    // if we merge x + y, assume C is removed and now we need to update A and B

    // index: i, j, l
    // vals : w x+y z

    int ans = 0;
    while (!indices.empty()) {
      auto [sum, j] = *sums.begin();
      sums.erase(sums.begin());

      int i = -1, k = -1, l = -1;
      auto it = vals.find(j);
      assert(it != vals.end());

      if (it != vals.begin())
        i = prev(it)->first;
      auto it2 = next(it);
      if (it2 != vals.end()) {
        k = it2->first;
        it2 = next(it2);
        if (it2 != vals.end())
          l = it2->first;
      }
      assert(k != -1);

      // remove old states
      if (i != -1) {
        sums.erase({vals[i] + vals[j], i});
        indices.erase(i);
      }
      sums.erase({vals[j] + vals[k], j});
      indices.erase(j);
      if (l != -1) {
        sums.erase({vals[k] + vals[l], k});
        indices.erase(k);
      }

      // update new states
      vals[j] += vals[k];
      vals.erase(k);

      if (i != -1) {
        sums.insert({vals[i] + vals[j], i});
        if (vals[i] > vals[j])
          indices.insert(i);
      }
      if (l != -1) {
        sums.insert({vals[j] + vals[l], j});
        if (vals[j] > vals[l])
          indices.insert(j);
      }

      ans++;
    }
    return ans;
  }
};
