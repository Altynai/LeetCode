import java.util.*;
import java.util.function.Consumer;
import java.util.stream.Collectors;
import java.util.stream.IntStream;

class Solution {
    public int maxCandies(int[] status, int[] candies, int[][] keys, int[][] containedBoxes, int[] initialBoxes) {
        final int n = status.length;
        final Set<Integer> ownedUnopenedBoxes = new HashSet<>();
        final Set<Integer> ownedKeys = new HashSet<>();
        final Queue<Integer> queue = new ArrayDeque<>();
        final boolean[] visited = new boolean[n];
        final Consumer<Integer> enqueue = i -> {
            queue.add(i);
            status[i] = 1;
            visited[i] = true;
            for (int key : keys[i])
                ownedKeys.add(key);
        };
        for (int i : initialBoxes) {
            if (status[i] == 1) {
                enqueue.accept(i);
            } else {
                ownedUnopenedBoxes.add(i);
            }
        }

        while (!queue.isEmpty()) {
            final int i = queue.poll();
            for (int j : containedBoxes[i]) {
                if (status[j] == 1 && !visited[j])
                    enqueue.accept(j);
                if (status[j] == 0)
                    ownedUnopenedBoxes.add(j);
            }
            final Set<Integer> deleted = ownedUnopenedBoxes.stream().filter(ownedKeys::contains).collect(Collectors.toSet());
            for (int j : deleted)
                enqueue.accept(j);
            ownedUnopenedBoxes.removeAll(deleted);
        }
        return IntStream.range(0, n).map(i -> visited[i] ? candies[i] : 0).sum();
    }
}
