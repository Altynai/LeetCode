class Solution {
    private static long gcd(long x, long y) {
        return (y == 0) ? x : gcd(y, x % y);
    }

    public int nthUglyNumber(int n_, int a_, int b_, int c_) {
        long n = n_, a = a_, b = b_, c = c_;
        long ab = a / gcd(a, b) * b;
        long ac = a / gcd(a, c) * c;
        long bc = b / gcd(b, c) * c;
        long abc = ab / gcd(ab, c) * c;

        long l = 1, r = 2000000000, ans = -1;
        while (l <= r) {
            long m = (l + r) >> 1;
            long count = m / a + m / b + m / c - m / ab - m / bc - m / ac + m / abc;
            if (count >= n) {
                ans = m;
                r = m - 1;
            } else {
                l = m + 1;
            }
        }
        return ans;
    }
}
