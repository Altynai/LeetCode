class MinStack {
private:
    stack<int> main_stack;
    int min_value, min_count;

    void refresh() {
        if (main_stack.empty())
            return;
        int _min_value = top();

        stack<int> temp_stack;
        while (!main_stack.empty()) {
            int _top = main_stack.top();
            main_stack.pop();
            temp_stack.push(_top);
            _min_value = std::min(_top, _min_value);
        }

        min_value = _min_value;
        min_count = 0;
        while (!temp_stack.empty()) {
            int _top = temp_stack.top();
            temp_stack.pop();
            if (_top == min_value)
                min_count++;
            main_stack.push(_top);
        }
    }

public:
    void push(int x) {
        if (main_stack.empty()) {
            main_stack.push(x);
            min_value = x, min_count = 1;
        } else {
            main_stack.push(x);
            if (x == min_value)
                min_count++;
            else if (x < min_value)
                min_value = x, min_count = 1;
        }
    }

    void pop() {
        int x = top();
        main_stack.pop();
        if (x == min_value)
            min_count--;
        if (min_count == 0)
            refresh();
    }

    int top() {
        return main_stack.top();
    }

    int getMin() {
        return min_value;
    }
};