class Solution {
    public int findSpecialInteger(int[] arr) {
        final int n = arr.length;
        int pre = -1;
        int i = 0;
        while (i < n) {
            while (i < n && arr[i] == pre)
                i++;
            int l = i, r = n - 1, p = -1;
            while (l <= r) {
                int mid = (l + r) >> 1;
                if (arr[mid] == arr[i]) {
                    p = mid;
                    l = mid + 1;
                } else {
                    r = mid - 1;
                }
            }
            if ((p - i + 1) * 4 > n)
                return arr[i];
            pre = arr[p];
            i = p + 1;
        }
        return -1;
    }
}
