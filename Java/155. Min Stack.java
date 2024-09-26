
import java.util.ArrayList;
import java.util.List;

class MinStack1 {

    int min;
    List<Integer> stack;

    public MinStack1() {
        min = Integer.MAX_VALUE;
        stack = new ArrayList<>();
    }

    public void push(int val) {
        min = Math.min(min, val);
        stack.add(val);
    }

    public void pop() {
        int val = stack.getLast();
        stack.removeLast();
        if (val == min) {
            min = Integer.MAX_VALUE;
            for (int ele : stack)
                min = Math.min(min, ele);
        }
    }

    public int top() {
        return stack.getLast();
    }

    public int getMin() {
        return min;
    }
}

class MinStack {

    List<Integer> stack;
    List<Integer> minStack;

    public MinStack() {
        stack = new ArrayList<>();
        minStack = new ArrayList<>();
    }

    public void push(int val) {
        stack.add(val);
        minStack.add(Math.min(val, getMin()));
    }

    public void pop() {
        stack.removeLast();
        minStack.removeLast();
    }

    public int top() {
        return stack.getLast();
    }

    public int getMin() {
        if (minStack.isEmpty())
            return Integer.MAX_VALUE;
        return minStack.getLast();
    }
}