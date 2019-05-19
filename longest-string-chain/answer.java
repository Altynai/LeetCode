import java.util.Arrays;
import java.util.Comparator;

class Solution {
    private boolean isPredecessor(String a, String b) {
        if (a.length() + 1 != b.length())
            return false;
        int n = a.length(), i = 0;
        while (i < n && a.charAt(i) == b.charAt(i))
            i++;
        while (i < n && a.charAt(i) == b.charAt(i + 1))
            i++;
        return i == n;
    }

    public int longestStrChain(String[] words) {
        Arrays.sort(words, Comparator.comparingInt(String::length));
        int n = words.length;
        int[] dp = new int[n + 1];
        int ans = 1;
        Arrays.fill(dp, 1);
        for (int j = 0; j < n; j++) {
            for (int i = 0; i < j; i++) {
                if (isPredecessor(words[i], words[j]))
                    dp[j] = Math.max(dp[j], dp[i] + 1);
            }
            ans = Math.max(ans, dp[j]);
        }
        return ans;
    }
}
