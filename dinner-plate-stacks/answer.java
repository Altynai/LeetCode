import java.util.ArrayList;
import java.util.Stack;
import java.util.TreeSet;

class DinnerPlates {

    private int capacity;
    private ArrayList<Stack<Integer>> stacks;
    private TreeSet<Integer> notFull;
    private TreeSet<Integer> notEmpty;

    public DinnerPlates(int capacity) {
        this.capacity = capacity;
        stacks = new ArrayList<>();
        notFull = new TreeSet<>();
        notEmpty = new TreeSet<>();
    }

    private void push(int index, int val) {
        Stack<Integer> values = stacks.get(index);
        values.add(val);
        if (values.size() == capacity) {
            notFull.remove(index);
        } else {
            notFull.add(index);
        }
        notEmpty.add(index);
    }

    public void push(int val) {
        if (notFull.size() == 0) {
            stacks.add(new Stack<>());
            push(stacks.size() - 1, val);
        } else {
            push(notFull.first(), val);
        }
    }

    public int pop() {
        if (notEmpty.size() == 0)
            return -1;
        return popAtStack(notEmpty.last());
    }

    public int popAtStack(int index) {
        if (index >= stacks.size())
            return -1;
        Stack<Integer> values = stacks.get(index);
        if (values.empty())
            return -1;

        int ans = values.pop();
        if (values.size() == 0) {
            notEmpty.remove(index);
        } else {
            notEmpty.add(index);
        }
        notFull.add(index);
        return ans;
    }
}

/**
 * Your DinnerPlates object will be instantiated and called as such:
 * DinnerPlates obj = new DinnerPlates(capacity);
 * obj.push(val);
 * int param_2 = obj.pop();
 * int param_3 = obj.popAtStack(index);
 */
