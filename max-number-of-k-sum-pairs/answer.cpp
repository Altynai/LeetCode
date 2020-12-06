class Solution {
public:
  int maxOperations(vector<int> &a, int sum) {
    map<int, int> cnt;
    for (int num : a)
      cnt[num] += 1;

    int ans = 0;
    for (auto [k, v] : cnt) {
      if (k * 2 > sum)
        break;
      else if (k * 2 == sum)
        ans += v / 2;
      else {
        auto it = cnt.find(sum - k);
        if (it != cnt.end())
          ans += min(v, it->second);
      }
    }
    return ans;
  }
};
