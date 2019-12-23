import java.util.HashMap;
import java.util.concurrent.atomic.AtomicInteger;
import java.util.function.Consumer;

class Solution {
    private static final int N = 26;

    public int maxFreq(String s, int maxLetters, int minSize, int maxSize) {
        final int n = s.length();
        final HashMap<String, Integer> counter = new HashMap<>();
        int[] chars = new int[N];
        final AtomicInteger uniq = new AtomicInteger(0);
        final AtomicInteger total = new AtomicInteger(0);
        final Consumer<Integer> add = i -> {
            total.getAndIncrement();
            if (0 == chars[s.charAt(i) - 'a']++)
                uniq.getAndIncrement();
        };
        final Consumer<Integer> delete = i -> {
            total.getAndDecrement();
            if (0 == --chars[s.charAt(i) - 'a'])
                uniq.getAndDecrement();
        };
        for (int j = 0, i = 0; j < n; j++) {
            add.accept(j);
            while (uniq.get() > maxLetters)
                delete.accept(i++);
            if (uniq.get() <= maxLetters && minSize <= total.get()) {
                final String t = s.substring(i, i + minSize);
                counter.put(t, counter.getOrDefault(t, 0) + 1);
                delete.accept(i++);
            }
        }
        return counter.isEmpty() ? 0 : counter.values().stream().max(Integer::compareTo).get();
    }
}
