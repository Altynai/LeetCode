class Stack {
private:
    std::deque<int> queue;
public:
    Stack() {
        queue = deque<int>();
    }
    // Push element x onto stack.
    void push(int x) {
        this->queue.push_front(x);
    }

    // Removes the element on top of the stack.
    void pop() {
        this->queue.pop_front();
    }

    // Get the top element.
    int top() {
        return this->queue.front();
    }

    // Return whether the stack is empty.
    bool empty() {
        return this->queue.empty();
    }
};