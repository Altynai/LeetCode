import java.util.Arrays;
import java.util.List;
import java.util.stream.Collectors;

class Solution {

    public String lastSubstring(String s) {
        SuffixArray sa = new SuffixArray(s);
        int index = sa.entries[s.length() - 1].index;
        return s.substring(index);
    }
}

class RadixSorter {
    private int n;
    private int[] count;
    private Entry[] tmp;

    public RadixSorter(int n) {
        this.n = n;
        count = new int[n];
        tmp = new Entry[n];
    }

    public void sort(Entry[] entries) {
        n = entries.length;
        countSort(entries, false);
        countSort(entries, true);
    }

    private void countSort(Entry[] entries, boolean useA) {
        Arrays.fill(count, 0);
        int negtive = 0;
        for (int i = 0; i < n; i++) {
            int v = (useA ? entries[i].a : entries[i].b);
            if (v == -1)
                negtive++;
            else
                count[v]++;
        }
        for (int i = 1; i < n; i++)
            count[i] += count[i - 1];

        int p = negtive - 1;
        for (int i = n - 1; i >= 0; i--) {
            int v = (useA ? entries[i].a : entries[i].b);
            if (v == -1)
                tmp[p--] = entries[i];
            else {
                tmp[negtive - 1 + count[v]] = entries[i];
                count[v]--;
            }
        }
        System.arraycopy(tmp, 0, entries, 0, n);
    }
}

class SuffixArray {
    // https://web.stanford.edu/class/cs97si/suffix-array.pdf
    // Use default sort: O(n * logn * logn)
    // Use radix sort: O(n * logn)
    public Entry[] entries;
    private int[][] rank;
    private int n;

    public SuffixArray(final String text) {
        n = text.length();
        initEntry();
        initRank(text);
        RadixSorter radixSorter = new RadixSorter(n);
        for (int level = 1, step = 1; (step >> 1) < n; level++, step <<= 1) {
            for (int i = 0; i < n; i++) {
                entries[i].a = rank[i][level - 1];
                entries[i].b = i + step < n ? rank[i + step][level - 1] : -1;
                entries[i].index = i;
            }
//            Arrays.sort(entries);
            radixSorter.sort(entries);
            for (int i = 0; i < n; i++) {
                rank[entries[i].index][level] =
                        i > 0 && entries[i].a == entries[i - 1].a && entries[i].b == entries[i - 1].b ?
                                rank[entries[i - 1].index][level] : i;
            }
        }
    }

    private void initEntry() {
        entries = new Entry[n];
        for (int i = 0; i < n; i++)
            entries[i] = new Entry(0, 0, i);
    }

    private void initRank(final String text) {
        // make sure first level fits in size 26
        int m = (int) Math.floor(Math.log((double) (n)) / Math.log(2.0));
        rank = new int[n][m + 10];

        List<Character> characters = text.chars().mapToObj(c -> (char) c).distinct().collect(Collectors.toList());
        char[] seen = new char[characters.size()];
        for (int i = 0; i < characters.size(); i++)
            seen[i] = characters.get(i);
        Arrays.sort(seen);
        for (int i = 0; i < n; i++)
            rank[i][0] = Arrays.binarySearch(seen, text.charAt(i));
    }
}

class Entry implements Comparable<Entry> {
    int a; // rank of suffix[index:] at level k
    int b; // rank of suffix[index + 2 ^ k:] at level k
    int index;

    public Entry(int a, int b, int index) {
        this.a = a;
        this.b = b;
        this.index = index;
    }

    @Override
    public int compareTo(Entry other) {
        if (a == other.a) {
            if (b == other.b)
                return 0;
            return b < other.b ? -1 : 1;
        }
        return a < other.a ? -1 : 1;
    }
}
