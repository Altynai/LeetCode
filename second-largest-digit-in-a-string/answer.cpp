class Solution {
public:
  int secondHighest(string s) {
    set<int> d;
    for (char ch : s) {
      if (isdigit(ch))
        d.insert(ch - '0');
    }
    vector<int> nums(d.begin(), d.end());
    int n = nums.size();
    return n >= 2 ? nums[n - 2] : -1;
  }
};
