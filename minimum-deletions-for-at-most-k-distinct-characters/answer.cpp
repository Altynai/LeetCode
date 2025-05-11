class Solution {
public:
  int minDeletion(string s, int k) {
    unordered_map<char, int> freq;
    for (char ch : s)
      freq[ch]++;

    vector<int> a;
    for (auto [_, v] : freq)
      a.push_back(v);

    int n = a.size();
    if (n <= k)
      return 0;

    sort(a.begin(), a.end());
    return accumulate(a.begin(), a.begin() + n - k, 0);
  }
};
