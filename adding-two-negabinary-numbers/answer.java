class Solution {
    public int[] addNegabinary(int[] arr1, int[] arr2) {
        int n1 = arr1.length, n2 = arr2.length;
        int n = Math.max(n1, n2);
        int m = n + 2;
        int[] p = new int[m];

        for (int i = n1 - 1, j = 0; i >= 0; i--, j++) {
            p[j] += arr1[i];
        }
        for (int i = n2 - 1, j = 0; i >= 0; i--, j++) {
            p[j] += arr2[i];
        }

        for (int i = 0; i + 2 < m; i++) {
            while (p[i] >= 2 && p[i + 1] > 0) {
                p[i] -= 2;
                p[i + 1]--;
            }
            while (p[i] >= 2) {
                p[i] -= 2;
                p[i + 1]++;
                p[i + 2]++;
            }
        }
        while (m > 1 && p[m - 1] == 0)
            m--;
        int[] ans = new int[m];
        for (int i = 0; i < m; i++) {
            ans[m - 1 - i] = p[i];
        }
        return ans;
    }
}
