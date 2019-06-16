class Solution {
    public void duplicateZeros(int[] arr) {
        int n = arr.length;
        int[] b = new int[n];
        int j = 0;
        for (int i = 0; j < n && i < n; i++) {
            b[j++] = arr[i];
            if (arr[i] == 0 && j < n)
                b[j++] = 0;
        }
        for (int i = 0; i < n; i++)
            arr[i] = b[i];
    }
}
