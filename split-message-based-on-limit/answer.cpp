class Solution {
public:
  int length(int x) {
    int ans = 0;
    while (x > 0)
      ans++, x /= 10;
    return ans;
  }

  int totalLength(int n) {
    int ans = 0, digits = 1, count = 9;
    for (int x = 1; true; x *= 10) {
      if (n < x * 10) {
        ans += digits * (n - x + 1);
        break;
      } else {
        ans += digits * count;
      }

      digits++;
      count *= 10;
    }
    return ans;
  }

  vector<string> splitMessage(string s, int m) {
    int n = s.size();
    int pages = -1;
    for (int k = 1; k <= n; k++) {
      // last page at least one char from s
      if (length(k) * 2 + 3 >= m)
        continue;

      int cnt = m * k - totalLength(k) - 3 * k - length(k) * k;
      if (cnt >= n) {
        pages = k;
        break;
      }
    }

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
