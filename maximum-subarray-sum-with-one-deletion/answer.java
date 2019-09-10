class Solution {
    public int maximumSum(int[] arr) {
        int n = arr.length;
        int[] a = new int[n + 2], b = new int[n + 2];
        for (int i = 1; i <= n; i++)
            a[i] = Math.max(arr[i - 1], a[i - 1] + arr[i - 1]);
        for (int i = n; i >= 1; i--)
            b[i] = Math.max(arr[i - 1], b[i + 1] + arr[i - 1]);
        int ans = arr[0], concat;
        for (int i = 1; i <= n; i++) {
            // without deletion
            ans = Math.max(ans, Math.max(a[i], b[i]));
            // with deletion
            if ((concat = Math.max(a[i - 1], b[i + 1])) > 0)
                ans = Math.max(ans, concat);
            if ((concat = a[i - 1] + b[i + 1]) > 0)
                ans = Math.max(ans, concat);
        }
        return ans;
    }
}
