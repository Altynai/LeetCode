class Solution {
public:
  int maxFrequency(vector<int> &a, int k, int op) {
    // assume a[x] <= .... <= a[y] <= ... <= a[z]
    // if a[y] is the final element, we can easily binary search the boundary
    // [x,  z] as index can only be selected once

    // but this means we don't perform operation on a[y], what if we did?
    // a[y] can become any integer P between a[y] - k and a[y] + k
    // how would that impact the answer?

    // as P can be anything, maybe we can just find a[x] <= ... <= a[z] <= a[x]
    // + 2k hence P can be achieved without doubt

    int n = a.size();
    sort(a.begin(), a.end());
    unordered_map<int, int> freq;
    for (int x : a)
      freq[x]++;

    int ans = 1;
    for (int i = 0; i < n; i++) {
      int l = lower_bound(a.begin(), a.begin() + i + 1, a[i] - k) - a.begin();
      int r = upper_bound(a.begin() + i, a.end(), a[i] + k) - 1 - a.begin();
      int diff = r - l + 1 - freq[a[i]];
      ans = max(ans, freq[a[i]] + min(diff, op));
    }

    for (int i = 0, j = 0; i < n; i++) {
      while (j < n and a[j] <= 1LL * a[i] + k + k)
        j++;
      ans = max(ans, min(op, j - i));
    }
    return ans;
  }
};
