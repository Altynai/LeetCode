import java.util.LinkedList;
import java.util.List;

class Solution {
    public String[] findOcurrences(String text, String first, String second) {
        String[] ss = text.split(" ");
        int n = ss.length;
        List<String> ans = new LinkedList<>();
        for (int i = 2; i < n; i++) {
            if (ss[i - 2].equals(first) && ss[i - 1].equals(second))
                ans.add(ss[i]);
        }
        return ans.toArray(new String[ans.size()]);
    }
}
