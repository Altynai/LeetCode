import java.util.ArrayList;
import java.util.Comparator;
import java.util.HashMap;
import java.util.Map;
import java.util.stream.Collectors;

class MajorityChecker {

    private Map<Integer, ArrayList<Integer>> seen;
    private ArrayList<int[]> freq;

    public MajorityChecker(int[] arr) {
        seen = new HashMap<>();
        for (int i = 0; i < arr.length; i++) {
            ArrayList<Integer> items = seen.getOrDefault(arr[i], new ArrayList<>());
            items.add(i);
            seen.put(arr[i], items);
        }
        freq = seen.entrySet().stream().map(entry -> new int[]{entry.getValue().size(), entry.getKey()})
                .collect(Collectors.toCollection(ArrayList::new));
        freq.sort(Comparator.comparingInt(e -> e[0]));
    }

    private int count(int number, int left, int right) {
        ArrayList<Integer> items = seen.get(number);
        int l = 0, r = items.size() - 1, i = -1, j = -2;
        while (l <= r) {
            int k = (l + r) >> 1;
            int index = items.get(k);
            if (left <= index && index <= right)
                r = (i = k) - 1;
            else if (index > right)
                r = k - 1;
            else
                l = k + 1;
        }
        l = 0;
        r = items.size() - 1;
        while (l <= r) {
            int k = (l + r) >> 1;
            int index = items.get(k);
            if (left <= index && index <= right)
                l = (j = k) + 1;
            else if (index < left)
                l = k + 1;
            else
                r = k - 1;
        }
        return j - i + 1;
    }

    public int query(int left, int right, int threshold) {
        for (int i = freq.size() - 1; i >= 0 && freq.get(i)[0] >= threshold; i--) {
            if (count(freq.get(i)[1], left, right) >= threshold)
                return freq.get(i)[1];
        }
        return -1;
    }
}

/**
 * Your MajorityChecker object will be instantiated and called as such:
 * MajorityChecker obj = new MajorityChecker(arr);
 * int param_1 = obj.query(left,right,threshold);
 */
