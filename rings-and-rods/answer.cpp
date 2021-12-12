class Solution {
public:
  int countPoints(string s) {
    vector<set<char>> rods(10);

    int n = s.size();
    for (int i = 0; i < n; i += 2)
      rods[s[i + 1] - '0'].insert(s[i]);

    int ans = 0;
    for (auto &rod : rods)
      if (rod.size() == 3)
        ans++;
    return ans;
  }
};
