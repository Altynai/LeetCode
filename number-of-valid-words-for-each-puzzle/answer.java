import java.util.Arrays;
import java.util.HashMap;
import java.util.List;
import java.util.Map;
import java.util.stream.Collectors;

class Solution {
    private int convert(String word) {
        int key = 0;
        for (int i = 0; i < word.length(); i++)
            key |= 1 << (word.charAt(i) - 'a');
        return key;
    }

    private int find(Map<Integer, Integer> count, String puzzle) {
        int first = 1 << (puzzle.charAt(0) - 'a'), key = convert(puzzle);
        int ans = 0;
        for (int bits = key; bits > 0; bits = (bits - 1) & key) {
            if ((bits & first) > 0)
                ans += count.getOrDefault(bits, 0);
        }
        return ans;
    }

    public List<Integer> findNumOfValidWords(String[] words, String[] puzzles) {
        Map<Integer, Integer> count = new HashMap<>();
        for (String word : words) {
            int key = convert(word);
            count.put(key, count.getOrDefault(key, 0) + 1);
        }
        return Arrays.stream(puzzles).map(puzzle -> find(count, puzzle)).collect(Collectors.toList());
    }
}
