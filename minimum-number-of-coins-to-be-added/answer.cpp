class Solution {
public:
  int minimumAddedCoins(vector<int> &coins, int target) {
    sort(coins.begin(), coins.end());
    int count = 0, i = 0;
    int cover = 0; // [0, cover] is always obtainable
    while (cover < target) {
      if (i < coins.size() && coins[i] <= cover + 1)
        cover += coins[i++];
      else
        cover += cover + 1, count++;
    }
    return count;
  }
};
