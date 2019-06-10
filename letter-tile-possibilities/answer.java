import java.util.Arrays;
import java.util.HashSet;

class Solution {
    private void swap(char[] s, int i, int j) {
        char tmp = s[i];
        s[i] = s[j];
        s[j] = tmp;
    }

    private boolean nextPermutation(char[] s, int n) {
        for (int i = n - 2; i >= 0; i--) {
            if (s[i + 1] > s[i]) {
                int j;
                for (j = n - 1; j > i; j--) {
                    if (s[j] > s[i]) {
                        break;
                    }
                }
                swap(s, i, j);
                for (int x = i + 1, y = n - 1; x <= y; x++, y--)
                    swap(s, x, y);
                return true;
            }
        }
        return false;
    }

    public int numTilePossibilities(String tiles) {
        int n = tiles.length();
        char[] chs = new char[n];
        HashSet<String> seen = new HashSet<>();
        int m = (1 << n);
        for (int i = 1; i < m; i++) {
            int cnt = 0;
            for (int j = 0; j < n; j++) {
                if ((i & (1 << j)) > 0) {
                    chs[cnt++] = tiles.charAt(j);
                }
            }
            Arrays.sort(chs, 0, cnt);
            do {
                seen.add(String.valueOf(chs, 0, cnt));
            } while (nextPermutation(chs, cnt));
        }
        return seen.size();
    }
}
