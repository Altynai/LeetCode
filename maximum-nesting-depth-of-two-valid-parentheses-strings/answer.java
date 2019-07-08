class Solution {
    public int[] maxDepthAfterSplit(String seq) {
        int n = seq.length(), top = 0;
        int[] ans = new int[n];
        Item[] stack = new Item[n + 1];
        for (int i = 0; i < n; i++) {
            if (seq.charAt(i) == '(') {
                int tag = (top == 0) ? 0 : stack[top - 1].tag ^ 1;
                stack[top++] = new Item(i, tag);
                ans[i] = tag;
            } else {
                Item item = stack[--top];
                ans[i] = item.tag;
            }
        }
        return ans;
    }

    class Item {
        int i;
        int tag;

        public Item(int i, int tag) {
            this.i = i;
            this.tag = tag;
        }
    }
}
