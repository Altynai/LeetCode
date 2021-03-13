class Solution {
public:
  int beautySum(string s) {
    int n = s.size();
    int ans = 0;
    for (int i = 0; i < n; i++) {
      vector<int> cnt(26, 0);
      multiset<int> ms;
      for (int j = i; j < n; j++) {
        int a = cnt[s[j] - 'a'];
        int b = ++cnt[s[j] - 'a'];
        if (a)
          ms.erase(ms.find(a));
        ms.insert(b);
        ans += (*ms.rbegin() - *ms.begin());
      }
    }
    return ans;
  }
};
