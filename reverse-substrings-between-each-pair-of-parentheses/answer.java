import java.util.ArrayList;
import java.util.Stack;

class Solution {

    public String reverseParentheses(String s) {
        int p = 0, i = 0;
        Stack<Item> items = new Stack<>();
        while (i < s.length()) {
            if (s.charAt(i) == '(') {
                p++;
                i++;
                final StringBuffer sb = new StringBuffer().append('(');
                items.add(new Item(sb, false));
            } else if (s.charAt(i) == ')') {
                final ArrayList<Item> temp = new ArrayList<>();
                while (!items.peek().isLeftParenthes()) {
                    final Item top = items.pop();
                    top.switchReverse();
                    temp.add(top);
                }
                items.pop();
                items.addAll(temp);
                p--;
                i++;
            } else {
                final StringBuffer sb = new StringBuffer();
                while (i < s.length() && Character.isLowerCase(s.charAt(i)))
                    sb.append(s.charAt(i++));
                items.add(new Item(sb, false));
            }
        }
        StringBuilder ans = new StringBuilder();
        for (Item item : items) {
            item.reverse();
            ans.append(item.sb);
        }
        return ans.toString();
    }

    class Item {
        public StringBuffer sb;
        public boolean needReverse;

        public Item(StringBuffer sb, boolean needReverse) {
            this.sb = sb;
            this.needReverse = needReverse;
        }

        public void reverse() {
            if (this.needReverse) {
                this.sb.reverse();
                switchReverse();
            }
        }

        public void switchReverse() {
            this.needReverse = !needReverse;
        }

        public boolean isLeftParenthes() {
            return sb.length() == 1 && sb.charAt(0) == '(';
        }
    }
}
