class Solution {
    private boolean seen[];
    private StringBuilder ans;

    private void dfs(String text) {
        if (text.equals(""))
            return;

        int n = text.length();
        int[] cnt = new int[26], uniq = new int[n];
        cnt[text.charAt(n - 1) - 'a']++;
        uniq[n - 1] = 1;
        for (int i = n - 2; i >= 0; i--) {
            uniq[i] = uniq[i + 1];
            if (++cnt[text.charAt(i) - 'a'] == 1)
                uniq[i]++;
        }
        int j = 0;
        for (int i = 0; i < n && uniq[i] == uniq[0]; i++) {
            if (text.charAt(i) < text.charAt(j))
                j = i;
        }
        ans.append(text.charAt(j));
        seen[text.charAt(j) - 'a'] = true;
        
        StringBuilder sb = new StringBuilder();
        for (int i = j + 1; i < n; i++) {
            if (!seen[text.charAt(i) - 'a'])
                sb.append(text.charAt(i));
        }
        dfs(sb.toString());
    }

    public String smallestSubsequence(String text) {
        seen = new boolean[26];
        ans = new StringBuilder();
        dfs(text);
        return ans.toString();
    }
}
