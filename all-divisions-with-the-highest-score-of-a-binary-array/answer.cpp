class Solution {
public:
  vector<int> maxScoreIndices(vector<int> &a) {
    vector<int> left(2, 0), right(2, 0);
    for (int x : a)
      right[x]++;

    vector<int> ans;
    int best = 0, n = a.size();
    for (int i = 0; i <= n; i++) {
      int score = left[0] + right[1];
      if (score > best)
        best = score, ans = {i};
      else if (score == best)
        ans.push_back(i);

      if (i < n)
        left[a[i]]++, right[a[i]]--;
    }
    return ans;
  }
};
