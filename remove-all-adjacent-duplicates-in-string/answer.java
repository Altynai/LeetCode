import java.util.Stack;

class Solution {
    public String removeDuplicates(String S) {
        Stack<Character> stack = new Stack<>();
        for (Character character : S.toCharArray()) {
            if (!stack.empty() && stack.peek() == character) {
                stack.pop();
            } else {
                stack.push(character);
            }
        }
        StringBuilder sb = new StringBuilder();
        for (Character c : stack) {
            sb.append(c);
        }
        return sb.toString();
    }
}
