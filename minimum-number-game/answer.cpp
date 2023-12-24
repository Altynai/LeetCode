class Solution {
public:
  vector<int> numberGame(vector<int> &a) {
    vector<int> ans;
    while (a.size() > 0) {
      sort(a.begin(), a.end());
      reverse(a.begin(), a.end());

      int alice = a.back();
      a.pop_back();
      int bob = a.back();
      a.pop_back();

      ans.push_back(bob);
      ans.push_back(alice);
    }
    return ans;
  }
};
