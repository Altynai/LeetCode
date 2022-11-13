class Solution {
public:
  int length(int x) {
    int ans = 0;
    while (x > 0)
      ans++, x /= 10;
    return ans;
  }

  vector<string> splitMessage(string s, int m) {
    int n = s.size();
    int pages = -1;

    for (int l = 1, r = n; l <= r;) {
      int mid = (l + r) / 2;

      bool ok = true;
      int j = 0;
      for (int i = 1; ok and i <= mid; i++) {
        int suffix_len = length(i) + length(mid) + 3;
        if (suffix_len >= m)
          ok = false;
        else
          j += (m - suffix_len);
      }

      if (ok and j >= n)
        pages = mid, r = mid - 1;
      else
        l = mid + 1;
    }

    if (pages == -1)
      return {};

    vector<string> ans;
    for (int i = 1, j = 0; i <= pages; i++) {
      int suffix_len = length(i) + length(pages) + 3;
      int k = min(n, j + (m - suffix_len));

      string t = s.substr(j, k - j) + "<" + to_string(i) + "/" +
                 to_string(pages) + ">";
      ans.push_back(t);

      j = k;
    }
    return ans;
  }
};
