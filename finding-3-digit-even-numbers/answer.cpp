class Solution {
public:
  vector<int> findEvenNumbers(vector<int> &a) {
    int n = a.size();
    vector<int> cnt(10, 0);
    for (int x : a)
      cnt[x]++;

    vector<int> ans;
    for (int i = 100; i < 1000; i += 2) {
      vector<int> cc(10, 0);
      bool ok = true;
      for (int x = i; x > 0; x /= 10)
        if (++cc[x % 10] > cnt[x % 10])
          ok = false;
      if (ok)
        ans.push_back(i);
    }
    return ans;
  }
};
