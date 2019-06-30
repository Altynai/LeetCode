import java.util.HashSet;
import java.util.Set;

enum Type {
    SET,
    LEFT,
    COMMA,
    NOT,
    AND,
    OR,
}

class Node {
    public Type type = null;
    public Set<Boolean> set = new HashSet<>();

    Node(char ch) {
        if (ch == '(') type = Type.LEFT;
        if (ch == ',') type = Type.COMMA;
        if (ch == '!') type = Type.NOT;
        if (ch == '&') type = Type.AND;
        if (ch == '|') type = Type.OR;
    }

    Node(Set<Boolean> set) {
        this.set = set;
        type = Type.SET;
    }

    public boolean isLogical() {
        return type == Type.AND || type == Type.NOT || type == Type.OR;
    }
}

class Solution {
    private Node[] stack;
    private int top;

    private void logical() {
        while (top > 1 && stack[top - 1].type == Type.SET && stack[top - 2].isLogical()) {
            Set<Boolean> set = new HashSet<>();
            if (stack[top - 2].type == Type.AND)
                set.add(!stack[top - 1].set.contains(false));
            else if (stack[top - 2].type == Type.OR)
                set.add(stack[top - 1].set.contains(true));
            else
                set.add(stack[top - 1].set.contains(false));
            stack[top - 2] = new Node(set);
            top--;
        }
    }

    private void mergeSet() {
        while (top > 3 && stack[top - 1].type == Type.SET && stack[top - 2].type == Type.COMMA && stack[top - 3].type == Type.SET) {
            stack[top - 3].set.addAll(stack[top - 1].set);
            top -= 2;
        }
        if (top > 1 && stack[top - 2].type == Type.LEFT) {
            stack[top - 2] = stack[top - 1];
            top--;
        }
    }

    public boolean parseBoolExpr(String expression) {
        int n = expression.length();
        top = 0;
        stack = new Node[n + 1];

        for (int i = 0; i < n; i++) {
            char ch = expression.charAt(i);
            if (ch == '(' || ch == ',' || ch == '!' || ch == '&' || ch == '|') {
                stack[top++] = new Node(ch);
            } else if (ch == 't' || ch == 'f') {
                Set<Boolean> set = new HashSet<>();
                set.add(ch == 't');
                stack[top++] = new Node(set);
            } else if (ch == ')') {
                mergeSet();
                logical();
            }
        }
        return stack[0].set.contains(true);
    }
}
