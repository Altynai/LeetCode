class Solution {
public:
  string kthDistinct(vector<string> &arr, int k) {
    map<string, int> cnt;
    for (string b : arr)
      cnt[b]++;

    set<string> s;
    int now = 0;
    for (string b : arr) {
      if (cnt[b] != 1)
        continue;
      if (s.count(b))
        continue;
      s.insert(b);
      if (++now == k)
        return b;
    }
    return "";
  }
};
