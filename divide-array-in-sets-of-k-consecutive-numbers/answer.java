import java.util.Map;
import java.util.TreeMap;

class Solution {
    public boolean isPossibleDivide(int[] nums, int k) {
        if (nums.length % k != 0)
            return false;
        TreeMap<Integer, Integer> counter = new TreeMap<>();
        for (int num : nums) {
            counter.put(num, counter.getOrDefault(num, 0) + 1);
        }
        while (!counter.isEmpty()) {
            final Map.Entry<Integer, Integer> first = counter.firstEntry();
            final int count = first.getValue();
            final int s = first.getKey();
            for (int i = s; i < s + k; i++) {
                if (counter.getOrDefault(i, 0) < count)
                    return false;
            }
            for (int i = s; i < s + k; i++) {
                final int value = counter.get(i);
                if (value == count)
                    counter.remove(i);
                else
                    counter.replace(i, value - count);
            }
        }
        return true;
    }
}
