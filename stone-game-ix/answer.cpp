class Solution {
public:
  bool stoneGameIX(vector<int> &s) {
    if (s.size() == 1)
      return 0;

    vector<int> cnt(3, 0);
    for (int val : s)
      cnt[val % 3]++;
    cnt[0] %= 2;

    if (cnt[0] == 0) {
      // Bob can always win no matter (cnt[1] + cnt[2]) < 3 or >= 3 (Alice will
      // pick the 3rd one)
      if (cnt[1] == 0 || cnt[2] == 0)
        return 0;
      // cnt[1] > 0 && cnt[2] > 0
      // Alice can always win if she starts from the less pile
      return 1;
    } else {
      if (cnt[1] == 0 && cnt[2] == 0)
        return 0;

      // cnt[1] > 0 || cnt[2] > 0
      if (cnt[1] == 0 || cnt[2] == 0) {
        // Similar case, assume Alice has to pick 1 first:
        // only one 1, seq: 1, 0 -> false
        //      two 1, seq: 1, 0, 1 -> false
        //    three 1, seq: 1, 0, 1, 1 -> true
        return max(cnt[1], cnt[2]) >= 3;
      } else {
        // cnt[1] > 0 && cnt[2] > 0
        return abs(cnt[1] - cnt[2]) > 2;
      }
    }
    return 0;
  }
};
