class Solution {
public:
  vector<int> findLonely(vector<int> &a) {
    int N = *max_element(a.begin(), a.end());
    vector<int> cnt(N + 1, 0);
    for (int x : a)
      cnt[x]++;

    vector<int> ans;
    for (int x : a) {
      if (cnt[x] != 1)
        continue;
      if (x and cnt[x - 1])
        continue;
      if (x + 1 <= N and cnt[x + 1])
        continue;
      ans.push_back(x);
    }
    return ans;
  }
};
