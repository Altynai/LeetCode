import java.util.Arrays;
import java.util.List;
import java.util.stream.Collectors;

class Solution {

    private int[][] count;

    private boolean check(int[] query) {
        int l = query[0] + 1, r = query[1] + 1, k = query[2];
        int odds = 0;
        for (int i = 0; i < 26; i++)
            odds += (count[r][i] - count[l - 1][i]) % 2;
        return (r - l + 1) % 2 == 0 ? k * 2 >= odds : k * 2 >= (odds - 1);
    }

    public List<Boolean> canMakePaliQueries(String s, int[][] queries) {
        int n = s.length();
        count = new int[n + 1][26];
        for (int i = 1; i <= n; i++) {
            for (int j = 0; j < 26; j++)
                count[i][j] = count[i - 1][j] + (s.charAt(i - 1) - 'a' == j ? 1 : 0);
        }
        return Arrays.stream(queries).map(this::check).collect(Collectors.toList());
    }
}
