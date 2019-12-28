import java.util.Arrays;

class Solution {
    private int difference;
    private int value;
    private int n;

    private void tryUpdate(int sum, int left, int v, int target) {
        int diff = Math.abs(sum + left * v - target);
        if (difference == -1 || diff < difference) {
            difference = diff;
            value = v;
        }
    }

    public int findBestValue(int[] arr, int target) {
        n = arr.length;
        value = -1;
        difference = -1;
        Arrays.sort(arr);

        int v = target / n;
        if (v <= arr[0]) tryUpdate(0, n, v, target);
        if (v + 1 <= arr[0]) tryUpdate(0, n, v + 1, target);

        for (int i = 0, sum = 0; i + 1 < n; i++) {
            sum += arr[i];
            v = (target - sum) / (n - 1 - i);
            if (arr[i] <= v && v < arr[i + 1]) tryUpdate(sum, n - 1 - i, v, target);
            if (arr[i] <= v + 1 && v + 1 < arr[i + 1]) tryUpdate(sum, n - 1 - i, v + 1, target);
            tryUpdate(sum, n - 1 - i, arr[i], target);
        }
        tryUpdate(Arrays.stream(arr).sum(), 0, arr[n - 1], target);
        return value;
    }
}
