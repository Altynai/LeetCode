class Solution {
    private int[] count;

    private static boolean inState(int state, int i) {
        return (state & (1 << i)) > 0;
    }

    private boolean okay2Add(String[] words, int state, int i) {
        if (inState(state, i))
            return false;
        int[] c = new int[26];
        for (int j = 0; j < words.length; j++) {
            if (inState(state, j) || i == j)
                for (char letter : words[j].toCharArray()) c[letter - 'a'] += 1;
        }
        for (int j = 0; j < 26; j++) {
            if (c[j] > count[j])
                return false;
        }
        return true;
    }

    private int calculate(String word, int[] score) {
        int s = 0;
        for (char letter : word.toCharArray()) s += score[letter - 'a'];
        return s;
    }

    public int maxScoreWords(String[] words, char[] letters, int[] score) {
        count = new int[26];
        for (char letter : letters) count[letter - 'a'] += 1;

        int n = words.length;
        int[] dp = new int[1 << n];
        int ans = 0;
        for (int state = 0; state < (1 << n); state++) {
            for (int i = 0; i < n; i++) {
                if (!inState(state, i) && okay2Add(words, state, i)) {
                    dp[state | (1 << i)] = Math.max(dp[state | (1 << i)], dp[state] + calculate(words[i], score));
                    ans = Math.max(ans, dp[state | (1 << i)]);
                }
            }
        }
        return ans;
    }
}
