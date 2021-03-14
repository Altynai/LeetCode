class Solution {
public:
  bool areAlmostEqual(string s1, string s2) {
    int n = s1.size();
    vector<int> diff;
    for (int i = 0; i < n; i++) {
      if (s1[i] != s2[i])
        diff.push_back(i);
    }
    return diff.size() == 0 ||
           (diff.size() == 2 && s1[diff[0]] == s2[diff[1]] &&
            s1[diff[1]] == s2[diff[0]]);
  }
};
