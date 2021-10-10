class Solution {
public:
  vector<int> twoOutOfThree(vector<int> &a, vector<int> &b, vector<int> &c) {
    const int N = 100;
    vector<int> ans;
    vector<int> cnt(N + 1, 0);
    for (auto &v : {a, b, c}) {
      vector<bool> seen(N + 1, 0);
      for (int k : v) {
        if (!seen[k]) {
          if (++cnt[k] == 2)
            ans.push_back(k);
        }
        seen[k] = 1;
      }
    }
    return ans;
  }
};
