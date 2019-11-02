import java.util.List;
import java.util.stream.IntStream;

class Solution {
    private int solve(int mask, int[] h, int[] len) {
        int state = 0, ans = 0;
        for (int i = 0; i < 26; i++) {
            if ((mask & (1 << i)) > 0) {
                if ((state | h[i]) != state + h[i])
                    return 0;
                state |= h[i];
                ans += len[i];
            }
        }
        return ans;
    }

    public int maxLength(List<String> arr) {
        int n = arr.size();
        int[] h = new int[n];
        int[] len = new int[n];
        for (int i = 0; i < n; i++) {
            String s = arr.get(i);
            len[i] = s.length();
            for (int j = 0; j < s.length(); j++) {
                int p = 1 << (s.charAt(j) - 'a');
                if ((h[i] & p) > 0) {
                    h[i] = 0;
                    len[i] = 0;
                    break;
                } else
                    h[i] |= p;
            }
        }
        return IntStream.range(0, 1 << n).map(mask -> solve(mask, h, len)).max().getAsInt();
    }
}
