class Solution {
    public int tribonacci(int n) {
        if (n <= 2)
            return n >= 1 ? 1 : 0;
        int[] p = new int[n + 1];
        p[1] = p[2] = 1;
        for (int i = 3; i <= n; i++)
            p[i] = p[i - 1] + p[i - 2] + p[i - 3];
        return p[n];
    }
}
