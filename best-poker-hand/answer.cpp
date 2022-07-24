class Solution {
public:
  string bestHand(vector<int> &ranks, vector<char> &suits) {
    sort(suits.begin(), suits.end());
    if (suits[0] == suits[4])
      return "Flush";

    map<int, int> cnt;
    for (int x : ranks)
      cnt[x]++;

    for (auto [k, v] : cnt) {
      if (v >= 3)
        return "Three of a Kind";
    }
    for (auto [k, v] : cnt) {
      if (v >= 2)
        return "Pair";
    }
    return "High Card";
  }
};
