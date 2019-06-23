import java.util.Arrays;
import java.util.HashSet;
import java.util.List;
import java.util.Set;
import java.util.stream.Collectors;

enum Type {
    LEFT,
    COMMA,
    SET
}

class Node {
    public Type type = null;
    public Set<String> set = new HashSet<>();

    Node(char ch) {
        type = (ch == '{') ? Type.LEFT : Type.COMMA;
    }

    Node(Set<String> set) {
        this.set = set;
        type = Type.SET;
    }
}

class Solution {
    private Node[] stack;
    private int top;

    private void multiplication() {
        while (top > 1 && stack[top - 1].type == Type.SET && stack[top - 2].type == Type.SET) {
            Set<String> result = new HashSet<>();
            for (String a : stack[top - 2].set) {
                for (String b : stack[top - 1].set)
                    result.add(a + b);
            }
            stack[top - 2].set = result;
            top--;
        }
    }

    private void addition() {
        while (top > 3 && stack[top - 1].type == Type.SET && stack[top - 2].type == Type.COMMA && stack[top - 3].type == Type.SET) {
            stack[top - 3].set.addAll(stack[top - 1].set);
            top -= 2;
        }
        if (top > 1 && stack[top - 2].type == Type.LEFT) {
            stack[top - 2] = stack[top - 1];
            top--;
        }
    }

    public List<String> braceExpansionII(String expression) {
        int n = expression.length();
        top = 0;
        stack = new Node[n + 1];

        for (int i = 0; i < n; ) {
            if (expression.charAt(i) == '{' || expression.charAt(i) == ',')
                stack[top++] = new Node(expression.charAt(i++));
            else if (expression.charAt(i) == '}') {
                addition();
                multiplication();
                i++;
            } else {
                // read next string
                StringBuilder sb = new StringBuilder();
                while (i < n && Character.isLowerCase(expression.charAt(i)))
                    sb.append(expression.charAt(i++));
                stack[top++] = new Node(new HashSet<>(Arrays.asList(sb.toString())));
                multiplication();
            }
        }
        addition();
        return stack[0].set.stream().sorted().collect(Collectors.toList());
    }
}
