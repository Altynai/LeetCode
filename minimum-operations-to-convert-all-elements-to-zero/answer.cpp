class Solution {
public:
  int minOperations(vector<int> &a) {
    vector<int> v;
    int ans = 0;
    for (int x : a) {

      while (v.size() > 0 and v.back() > x)
        v.pop_back();

      if (v.size() == 0 or x > v.back()) {
        if (x > 0)
          ans++;
        v.push_back(x);
      }
    }
    return ans;
  }
};
