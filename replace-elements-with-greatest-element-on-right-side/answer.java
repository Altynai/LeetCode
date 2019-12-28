class Solution {
    public int[] replaceElements(int[] arr) {
        final int n = arr.length;
        final int[] ans = new int[n];
        ans[n - 1] = -1;
        int mx = arr[n - 1];
        for (int i = n - 2; i >= 0; i--) {
            ans[i] = mx;
            mx = Math.max(arr[i], mx);
        }
        return ans;
    }
}
