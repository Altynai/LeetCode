import java.util.ArrayList;

class Solution {
    private String text;
    private int n;
    private int[] count;

    public int maxRepOpt1(String text) {
        this.text = text;
        n = text.length();
        count = new int[26];

        for (int i = 0; i < n; i++)
            count[text.charAt(i) - 'a']++;

        int ans = 0;
        for (char c = 'a'; c <= 'z'; c++)
            ans = Math.max(ans, solve(c));
        return ans;
    }

    private int solve(char c) {
        int all = count[c - 'a'];
        if (all == 0)
            return 0;
        ArrayList<int[]> ranges = new ArrayList<>();
        int s = -1, e = -1;
        for (int i = 0; i < n; i++) {
            if (text.charAt(i) == c) {
                if (s == -1) {
                    s = i;
                    e = i;
                }
                e++;
            }
            if (text.charAt(i) != c || i == n - 1) {
                if (s != -1 && e != -1) {
                    ranges.add(new int[]{s, e});
                    s = -1;
                    e = -1;
                }
            }
        }

        int ans = ranges.get(0)[1] - ranges.get(0)[0];
        for (int i = 1; i < ranges.size(); i++) {
            int[] pre = ranges.get(i - 1), cur = ranges.get(i);
            ans = Math.max(ans, Math.max(pre[1] - pre[0], cur[1] - cur[0]) + 1);
            if (pre[1] + 1 == cur[0]) {
                int total = pre[1] - pre[0] + cur[1] - cur[0];
                ans = Math.max(ans, total < all ? total + 1 : total);
            }
        }
        return ans;
    }
}
