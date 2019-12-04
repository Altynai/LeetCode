import java.util.Arrays;
import java.util.Collections;
import java.util.List;

class Solution {
    public List<Integer> numOfBurgers(int tomatoSlices, int cheeseSlices) {
        int d = tomatoSlices - cheeseSlices * 2;
        return (d < 0 || d % 2 != 0 || cheeseSlices - d / 2 < 0) ? Collections.emptyList() :
                Arrays.asList(d / 2, cheeseSlices - d / 2);
    }
}
