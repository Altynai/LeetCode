import java.util.ArrayList;
import java.util.Arrays;
import java.util.Map;
import java.util.stream.Collectors;

class Solution {

    public int[] rearrangeBarcodes(int[] barcodes) {
        int n = barcodes.length;
        Map<Integer, Long> count = Arrays.stream(barcodes).boxed().collect(Collectors.groupingBy(barcode -> barcode, Collectors.counting()));
        int[] ans = new int[n];
        ArrayList<Map.Entry<Integer, Long>> pairs = count.entrySet().stream().sorted((e1, e2) -> e2.getValue().compareTo(e1.getValue()))
                .collect(Collectors.toCollection(ArrayList::new));
        int i = 0;
        for (Map.Entry<Integer, Long> pair : pairs) {
            int key = pair.getKey(), m = pair.getValue().intValue();
            for (int j = 0; j < m; j++, i += 2) {
                if (i >= n)
                    i = 1;
                ans[i] = key;
            }
        }
        return ans;
    }
}
