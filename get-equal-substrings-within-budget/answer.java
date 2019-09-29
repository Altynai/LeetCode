class Solution {
    public int equalSubstring(String s, String t, int maxCost) {
        int n = s.length();
        int l = 0, r = 0, cost = 0, ans = 0;
        while (r < n) {
            int diff = Math.abs(s.charAt(r) - t.charAt(r));
            if (cost + diff <= maxCost) {
                cost += diff;
                r++;
                ans = Math.max(ans, r - l);
            } else {
                cost -= Math.abs(s.charAt(l) - t.charAt(l));
                l++;
            }
        }
        return ans;
    }
}
