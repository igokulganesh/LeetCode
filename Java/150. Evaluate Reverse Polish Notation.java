
import java.util.Stack;

class Solution {
    public int evalRPN(String[] tokens) {
        Stack<Integer> stack = new Stack<>();
        for (String token : tokens) {
            if (isOperation(token))
                stack.add(evaluate(stack.pop(), stack.pop(), token));
            else
                stack.add(Integer.valueOf(token));
        }

        return stack.peek();
    }

    private Integer evaluate(int val1, int val2, String token) {
        return switch (token) {
            case "+" -> val1 + val2;
            case "-" -> val2 - val1;
            case "*" -> val1 * val2;
            case "/" -> val2 / val1;
            default -> 0;
        };
    }

    private boolean isOperation(String token) {
        return token.equals("+") || token.equals("-") || token.equals("*") || token.equals("/");
    }
}