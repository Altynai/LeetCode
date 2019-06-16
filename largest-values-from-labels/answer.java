import java.util.Arrays;
import java.util.HashMap;

class Solution {

    public int largestValsFromLabels(int[] values, int[] labels, int num_wanted, int use_limit) {
        int n = values.length;
        int[][] b = new int[n][2];
        for (int i = 0; i < n; i++) {
            b[i][0] = values[i];
            b[i][1] = labels[i];
        }
        Arrays.sort(b, (x, y) -> {
            if (x[0] != y[0])
                return (x[0] > y[0]) ? -1 : 1;
            else if (x[1] != y[1])
                return (x[1] < y[1]) ? -1 : 1;
            return 0;
        });
        HashMap<Integer, Integer> used = new HashMap<>();
        int sum = 0, count = 0;
        for (int i = 0; i < n && count < num_wanted; i++) {
            int j = used.getOrDefault(b[i][1], 0);
            if (j >= use_limit)
                continue;
            sum += b[i][0];
            count++;
            used.put(b[i][1], j + 1);
        }
        return sum;
    }
}
