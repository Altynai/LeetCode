#define bit(n, i) (((n) >> (i)) & 1)

const int N = 30;

class Solution {
public:
  vector<int> smallestSubarrays(vector<int> &a) {
    int n = a.size();
    vector<deque<int>> where(N);
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < N; j++) {
        if (bit(a[i], j))
          where[j].push_back(i);
      }
    }

    vector<int> ans(n);
    for (int i = 0; i < n; i++) {
      int k = i;
      for (int j = 0; j < N; j++) {
        if (where[j].size())
          k = max(k, where[j].front());
      }
      ans[i] = k - i + 1;
      for (int j = 0; j < N; j++) {
        if (bit(a[i], j))
          where[j].pop_front();
      }
    }
    return ans;
  }
};
