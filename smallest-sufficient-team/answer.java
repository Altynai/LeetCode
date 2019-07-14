import java.util.Arrays;
import java.util.HashMap;
import java.util.List;
import java.util.Map;

class Solution {
    public int[] smallestSufficientTeam(String[] req_skills, List<List<String>> people) {
        int n = req_skills.length;
        Map<String, Integer> skills = new HashMap<>();
        for (int i = 0; i < n; i++)
            skills.put(req_skills[i], i);

        int m = people.size();
        int[][] dp = new int[1 << n][m + 1];
        long[][] mask = new long[1 << n][m + 1];
        for (int[] row : dp)
            Arrays.fill(row, 0x3f3f3f3f);

        dp[0][0] = 0;
        for (int j = 1; j <= m; j++) {
            int state = 0;
            for (String skill : people.get(j - 1))
                state |= 1 << skills.get(skill);

            for (int i = 0; i < (1 << n); i++) {
                // skip jth person
                if (dp[i][j - 1] < dp[i][j]) {
                    dp[i][j] = dp[i][j - 1];
                    mask[i][j] = mask[i][j - 1];
                }
                // choose jth person
                int k = i | state;
                if (dp[i][j - 1] + 1 < dp[k][j]) {
                    dp[k][j] = dp[i][j - 1] + 1;
                    mask[k][j] = mask[i][j - 1] | ((long) 1 << j);
                }
            }
        }

        int i = (1 << n) - 1, j = -1;
        for (int k = 1; k <= m; k++) {
            if (j == -1 || dp[i][k] < dp[i][j])
                j = k;
        }

        int len = dp[i][j];
        int[] ans = new int[len];
        int w = 0;
        for (int k = 1; k <= m; k++) {
            if (((mask[i][j] >> k) & 1) > 0)
                ans[w++] = k - 1;
        }
        return ans;
    }
}
