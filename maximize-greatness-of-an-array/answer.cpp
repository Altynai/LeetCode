class Solution {
public:
  int maximizeGreatness(vector<int> &a) {
    multiset<int> s(a.begin(), a.end());

    int ans = 0;
    sort(a.begin(), a.end());
    for (int x : a) {
      auto it = s.upper_bound(x);
      if (it != s.end())
        ans++, s.erase(it);
    }
    return ans;
  }
};
