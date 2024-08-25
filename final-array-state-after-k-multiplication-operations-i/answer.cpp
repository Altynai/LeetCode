class Solution {
public:
  vector<int> getFinalState(vector<int> &a, int k, int multiplier) {
    int n = a.size();
    while (k--) {
      int i = min_element(a.begin(), a.end()) - a.begin();
      a[i] *= multiplier;
    }
    return a;
  }
};

