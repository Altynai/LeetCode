class Solution {
public:
  int minLengthAfterRemovals(vector<int> &a) {
    int n = a.size(), matched = 0;
    for (int i = 0; i < n;) {
      int j = i;
      while (j < n and a[j] == a[i])
        j++;

      int lastMatched = matched;
      for (int k = i; k < j; k++) {
        // can we find another pair?
        int newMatched = matched + 2;
        if (k + 1 < newMatched)
          continue;

        // try use [i ... k] and pair some numbers from [0 ... i - 1]
        int used = k - i + 1;
        int otherMatched = newMatched - used * 2;
        if (otherMatched < 0)
          continue;
        if (otherMatched > lastMatched)
          continue;
        matched = newMatched;
      }
      i = j;
    }
    return n - matched;
  }
};
