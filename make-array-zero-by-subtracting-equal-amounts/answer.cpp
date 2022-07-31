class Solution {
public:
  int minimumOperations(vector<int> &nums) {
    set<int> s;
    for (int x : nums) {
      if (x > 0)
        s.insert(x);
    }
    return s.size();
  }
};
