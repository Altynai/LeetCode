class Solution {
public:
  vector<int> getSneakyNumbers(vector<int> &a) {
    int n = a.size();
    vector<int> cnt(n - 2, 0), ans;
    for (int x : a) {
      if (++cnt[x] == 2)
        ans.push_back(x);
    }
    return ans;
  }
};
