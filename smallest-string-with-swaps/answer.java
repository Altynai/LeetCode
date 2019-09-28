import java.util.List;
import java.util.stream.Collectors;
import java.util.stream.IntStream;

class DSU {
    private int n;
    private int[] p;

    public DSU(int n) {
        this.n = n;
        p = new int[n];
        for (int i = 0; i < n; i++) {
            p[i] = i;
        }
    }

    public int find(int x) {
        int r = x;
        while (p[r] != r)
            r = p[r];
        int i = x;
        while (p[i] != r) {
            int j = p[i];
            p[i] = r;
            i = j;
        }
        return r;
    }

    public void join(int x, int y) {
        p[find(x)] = find(y);
    }
}

class Solution {
    public String smallestStringWithSwaps(String s, List<List<Integer>> pairs) {
        int n = s.length();
        DSU dsu = new DSU(n);
        for (List<Integer> pair : pairs) {
            dsu.join(pair.get(0), pair.get(1));
        }
        char[] buf = new char[n];
        IntStream.range(0, n)
                .boxed()
                .collect(Collectors.groupingBy(dsu::find))
                .forEach((r, indexes) -> {
                    List<Character> values = indexes.stream().map(s::charAt).sorted().collect(Collectors.toList());
                    IntStream.range(0, indexes.size()).forEach(i -> buf[indexes.get(i)] = values.get(i));
                });
        return new String(buf);
    }
}
