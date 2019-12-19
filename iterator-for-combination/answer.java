import java.util.ArrayList;
import java.util.Comparator;
import java.util.List;
import java.util.stream.Collectors;
import java.util.stream.IntStream;

class CombinationIterator {

    private static int N = 31;
    private final String characters;
    private final List<Integer> states;
    private int offset;

    private static int countBit(final int state) {
        int cnt = 0;
        for (int i = 0; i < N; i++) {
            if ((state & (1 << i)) > 0)
                cnt++;
        }
        return cnt;
    }

    class StateComparator implements Comparator<Integer> {

        @Override
        public int compare(final Integer lh, final Integer rh) {
            for (int i = 0; i < N; i++) {
                int a = (lh & (1 << i)) > 0 ? 1 : 0;
                int b = (rh & (1 << i)) > 0 ? 1 : 0;
                if (a != b)
                    return b - a;
            }
            return 0;
        }
    }

    private String build(final int state) {
        final StringBuilder sb = new StringBuilder();
        for (int i = 0; i < N; i++) {
            if ((state & (1 << i)) > 0)
                sb.append(characters.charAt(i));
        }
        return sb.toString();
    }

    public CombinationIterator(String characters, int combinationLength) {
        this.characters = characters;
        this.states = IntStream.range(0, 1 << characters.length()).filter(
                state -> countBit(state) == combinationLength
        ).boxed().sorted(new StateComparator()).collect(Collectors.toList());
        this.offset = 0;
    }

    public String next() {
        return build(states.get(offset++));
    }

    public boolean hasNext() {
        return offset < states.size();
    }
}

/**
 * Your CombinationIterator object will be instantiated and called as such:
 * CombinationIterator obj = new CombinationIterator(characters, combinationLength);
 * String param_1 = obj.next();
 * boolean param_2 = obj.hasNext();
 */
