
import java.util.Stack;

class Solution {
    public String simplifyPath(String path) {
        String[] paths = path.split("/");
        Stack<String> stack = new Stack<>();
        int skip = 0;

        for (int i = paths.length - 1; i >= 0; i--) {
            if (paths[i].isEmpty() || paths[i].equals("."))
                continue;

            if (paths[i].equals(".."))
                skip++;
            else if (skip > 0)
                skip--;
            else
                stack.push(paths[i]);
        }

        StringBuilder sb = new StringBuilder();

        if (stack.isEmpty())
            sb.append("/");

        while (!stack.isEmpty())
            sb.append("/").append(stack.pop());

        return sb.toString();
    }
}