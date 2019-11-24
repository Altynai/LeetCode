import java.util.ArrayList;
import java.util.Collections;
import java.util.List;

class Solution {
    private static final int N = 26;
    private static final int K = 3;

    private Node root;

    public List<List<String>> suggestedProducts(String[] products, String searchWord) {
        root = new Node();
        for (String product : products)
            root.insert(product);
        root.calculateTop();

        List<List<String>> ans = new ArrayList<>();
        Node cur = root;
        for (int i = 0; i < searchWord.length(); i++) {
            int idx = searchWord.charAt(i) - 'a';
            cur = (cur == null) ? null : cur.children[idx];
            ans.add(cur == null ? Collections.emptyList() : cur.top);
        }
        return ans;
    }

    class Node {
        Node[] children;
        int count;
        List<String> top;

        public Node() {
            this.children = new Node[N];
            this.count = 0;
            this.top = new ArrayList<>();
        }

        public void insert(final String word) {
            Node root = this;
            for (int i = 0; i < word.length(); i++) {
                int idx = word.charAt(i) - 'a';
                if (root.children[idx] == null)
                    root.children[idx] = new Node();
                root = root.children[idx];
            }
            root.count++;
        }

        public void calculateTop() {
            StringBuffer sb = new StringBuffer();
            calculateTop(this, sb);
        }

        private List<String> calculateTop(final Node root, StringBuffer sb) {
            List<String> seen = new ArrayList<>();
            for (int i = 0; i < N; i++) {
                if (root.children[i] != null) {
                    int n = sb.length();
                    sb.append((char) ('a' + i));
                    seen.addAll(calculateTop(root.children[i], sb));
                    sb.deleteCharAt(n);
                }
            }
            for (int i = 0; i < Math.min(K, root.count); i++)
                seen.add(sb.toString());
            seen.sort(String::compareTo);
            root.top = seen.subList(0, Math.min(K, seen.size()));
            return root.top;
        }
    }
}
