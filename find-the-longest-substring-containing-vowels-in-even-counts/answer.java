import java.util.HashMap;
import java.util.Map;

class Solution {
  public int findTheLongestSubstring(String s) {
    final int n = s.length();
    final Map<Integer, Integer> mp = new HashMap<>();
    int ans = 0, state = 0;
    for (int i = 0; i < n; i++) {
      if (s.charAt(i) == 'a') state ^= 1;
      if (s.charAt(i) == 'e') state ^= 1 << 1;
      if (s.charAt(i) == 'i') state ^= 1 << 2;
      if (s.charAt(i) == 'o') state ^= 1 << 3;
      if (s.charAt(i) == 'u') state ^= 1 << 4;
      if (state == 0) ans = Math.max(ans, i + 1);
      if (mp.containsKey(state)) ans = Math.max(ans, i - mp.get(state));
      mp.putIfAbsent(state, i);
    }
    return ans;
  }
}
