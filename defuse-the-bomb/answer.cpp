class Solution {
public:
  vector<int> decrypt(vector<int> &code, int k) {
    int n = code.size();
    if (k == 0)
      return vector<int>(n, 0);

    vector<int> ans(n, 0);
    for (int i = 0; i < n; i++) {
      int j = i;
      for (int w = 0; w < abs(k); w++) {
        if (k > 0)
          j++;
        else
          j--;
        j = (j + n) % n;
        ans[i] += code[j];
      }
    }
    return ans;
  }
};
