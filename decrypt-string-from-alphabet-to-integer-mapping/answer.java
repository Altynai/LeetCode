class Solution {
    public String freqAlphabets(String s) {
        final StringBuilder sb = new StringBuilder();
        for (int i = s.length() - 1; i >= 0; ) {
            if (s.charAt(i) == '#') {
                int val = (s.charAt(i - 2) - '0') * 10 + (s.charAt(i - 1) - '0');
                sb.append((char) ('a' + val - 1));
                i -= 3;
            } else
                sb.append((char) ('a' + (s.charAt(i--) - '0') - 1));
        }
        sb.reverse();
        return sb.toString();
    }
}
