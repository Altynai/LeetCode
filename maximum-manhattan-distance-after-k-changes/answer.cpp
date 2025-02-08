class Solution {
public:
  int maxDistance(string s, int k) {
    int n = s.size();

    // a: NS b: WE
    auto CheckDirection = [&](char a, char b) -> int {
      int res = 0, cnt = k;
      int x = 0, y = 0;
      for (int i = 0; i < n; i++) {
        if (s[i] == 'N' or s[i] == 'S') {
          if (s[i] == a)
            y += (s[i] == 'N' ? +1 : -1);
          else if (cnt > 0)
            y += (a == 'N' ? +1 : -1), cnt--;
          else
            y += (a == 'N' ? -1 : +1);
        } else {
          if (s[i] == b)
            x += (s[i] == 'E' ? +1 : -1);
          else if (cnt > 0)
            x += (b == 'E' ? +1 : -1), cnt--;
          else
            x += (b == 'E' ? -1 : +1);
        }
        res = max(res, abs(x) + abs(y));
      }
      return res;
    };

    int ans = CheckDirection('N', 'E');
    ans = max(ans, CheckDirection('N', 'W'));
    ans = max(ans, CheckDirection('S', 'E'));
    ans = max(ans, CheckDirection('S', 'W'));
    return ans;
  }
};
