class Solution {
public:
  int minCost(vector<int> &startPos, vector<int> &homePos,
              vector<int> &rowCosts, vector<int> &colCosts) {
    int ans = 0;
    int r = startPos[0];
    while (r != homePos[0]) {
      r = (r < homePos[0] ? r + 1 : r - 1);
      ans += rowCosts[r];
    }

    int c = startPos[1];
    while (c != homePos[1]) {
      c = (c < homePos[1] ? c + 1 : c - 1);
      ans += colCosts[c];
    }
    return ans;
  }
};
