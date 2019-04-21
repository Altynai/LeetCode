class StreamChecker {

    class Node {
        Node[] child;
        boolean isWord;
        Node() {
            child = new Node[26];
            Arrays.fill(child, null);
            isWord = false;
        }
    }

    private Node root;
    private int len;
    private Deque<Character> deque; 

    public StreamChecker(String[] words) {
        root = new Node();
        deque = new LinkedList<Character>();
        int n = words.length;
        len = 0;
        for (int i = 0; i < n; i++) {
            Node t = root;
            len = Math.max(len, words[i].length());
            for (int j = words[i].length() - 1; j >= 0; j--) {
                int k = words[i].charAt(j) - 'a';
                if (t.child[k] == null)
                    t.child[k] = new Node();
                t = t.child[k];
            }
            t.isWord = true;
        }
    }
    
    public boolean query(char letter) {
        deque.addFirst(letter);
        if (deque.size() > len)
            deque.removeLast();
        Iterator iterator = deque.iterator();
        Node t = root;
        while (iterator.hasNext()) {
            int k = (char)iterator.next() - 'a';
            if (t.child[k] == null)
                return false;
            t = t.child[k];
            if (t.isWord)
                return true;
        }
        return false;
    }
}

/**
 * Your StreamChecker object will be instantiated and called as such:
 * StreamChecker obj = new StreamChecker(words);
 * boolean param_1 = obj.query(letter);
 */
