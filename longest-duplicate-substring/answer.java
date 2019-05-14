import java.util.HashMap;
import java.util.LinkedList;

class Solution {
    private int found(String S, int len) {
        HashMap<Long, LinkedList<Integer>> seen = new HashMap<>();
        long mod = 1_000_000_007;
        long hash = 0, p = 1;
        for (int i = 0; i < len; i++) {
            int a = S.charAt(i) - 'a';
            hash = (hash * 26 + a) % mod;
            p = (p * 26) % mod;
        }
        seen.putIfAbsent(hash, new LinkedList<>());
        seen.get(hash).add(0);
        for (int i = len; i < S.length(); i++) {
            int a = S.charAt(i - len) - 'a';
            int b = S.charAt(i) - 'a';
            hash = (hash * 26) % mod;
            hash = hash - ((a * p) % mod);
            hash = (hash + b + mod) % mod;
            seen.putIfAbsent(hash, new LinkedList<>());
            if (!seen.get(hash).isEmpty()) {
                String other = S.substring(i - len + 1, i + 1);
                for (int j : seen.get(hash)) {
                    if (S.substring(j, j + len).equals(other)) {
                        return j;
                    }
                }
            }
            seen.get(hash).add(i - len + 1);
        }
        return -1;
    }

    public String longestDupSubstring(String S) {
        int n = S.length();
        int l = 0, h = n - 1;
        int pos = 0, len = 0;
        while (l <= h) {
            int mid = (l + h) >> 1;
            int start = found(S, mid);
            if (start != -1) {
                pos = start;
                len = mid;
                l = mid + 1;
            } else {
                h = mid - 1;
            }
        }
        return S.substring(pos, pos + len);
    }
}
