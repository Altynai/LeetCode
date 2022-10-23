class Solution {
public:
    bool haveConflict(vector<string>& a, vector<string>& b) {
      return max(a[0], b[0]) <= min(a[1], b[1]);
    }
};
