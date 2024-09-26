
import java.util.Stack;

class Solution {
    public boolean isValid(String s) {
        Stack<Character> stack = new Stack<>();

        for (char c : s.toCharArray()) {
            if (isOpen(c))
                stack.add(c);
            else if (stack.isEmpty() || !isMatchingPair(stack.pop(), c))
                return false;
        }

        return stack.isEmpty();
    }

    private boolean isMatchingPair(char open, char close) {
        return switch (open) {
            case '(' -> close == ')';
            case '{' -> close == '}';
            case '[' -> close == ']';
            default -> false;
        };
    }

    private boolean isOpen(char c) {
        return (c == '(' || c == '{' || c == '[');
    }
}