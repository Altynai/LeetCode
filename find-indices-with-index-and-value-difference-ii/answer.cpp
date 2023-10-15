class Solution {
public:
  vector<int> findIndices(vector<int> &a, int indexDifference,
                          int valueDifference) {
    int n = a.size(), j = 0;
    map<int, int> where;
    for (int i = 0; i < n; i++) {
      while (j <= i - indexDifference)
        where[a[j++]] = j;
      // a[k] >= val
      int val = a[i] + valueDifference;
      auto it = where.lower_bound(val);
      if (it != where.end())
        return {i, it->second};

      // a[k] <= val
      val = a[i] - valueDifference;
      it = where.upper_bound(val);
      if (it != where.begin())
        return {i, prev(it)->second};
    }
    return vector<int>(2, -1);
  }
};
