class Solution {
    private int[] fenwick;

    void update(int i, int n, int value) {
        while (i <= n) {
            fenwick[i] += value;
            i += i & (-i);
        }
    }

    int sum(int i) {
        int ans = 0;
        while (i >= 1) {
            ans += fenwick[i];
            i -= i & (-i);
        }
        return ans;
    }

    public int[] corpFlightBookings(int[][] bookings, int n) {
        fenwick = new int[n + 1];
        for (int[] booking : bookings) {
            update(booking[0], n, booking[2]);
            update(booking[1] + 1, n, -booking[2]);
        }
        int[] ans = new int[n];
        for (int i = 0; i < n; i++)
            ans[i] = sum(i + 1);
        return ans;
    }
}
