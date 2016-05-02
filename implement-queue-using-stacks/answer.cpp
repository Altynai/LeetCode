class Queue {
private:
    std::deque<int> queue;

public:
    Queue() {
        queue = std::deque<int>();
    }
    // Push element x to the back of queue.
    void push(int x) {
        this->queue.push_back(x);
    }

    // Removes the element from in front of queue.
    void pop(void) {
        this->queue.pop_front();
    }

    // Get the front element.
    int peek(void) {
        return this->queue.front();
    }

    // Return whether the queue is empty.
    bool empty(void) {
        return this->queue.empty();
    }
};