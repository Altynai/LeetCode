import java.util.ArrayList;
import java.util.Collections;
import java.util.List;

class Solution {
    public List<Integer> pathInZigZagTree(int label) {
        int l = 1, r = 1;
        while (r < label) {
            l = l * 2;
            r = r * 2 + 1;
        }

        List<Integer> ans = new ArrayList<>();
        int n = label;
        while (n != 1) {
            n /= 2;
            l /= 2;
            r /= 2;
            n = l + r - n;
            ans.add(n);
        }
        Collections.reverse(ans);
        ans.add(label);
        return ans;
    }
}
