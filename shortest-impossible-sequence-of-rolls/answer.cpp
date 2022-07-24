class Solution {
public:
  int shortestSequence(vector<int> &rolls, int k) {
    int ans = 0;
    set<int> seen;
    for (int x : rolls) {
      seen.insert(x);
      if (seen.size() == k) {
        ans++;
        seen.clear();
      }
    }
    return ans + 1;
  }
};
