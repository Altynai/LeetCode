class MovingAverage {
public:
    deque<int> q;
    int size;
    double total;
    /** Initialize your data structure here. */
    MovingAverage(int size) {
        q.clear();
        total = 0;
        this->size = size;
    }

    double next(int val) {
        if (q.size() == size) {
            total -= q.back();
            q.pop_back();
        }
        q.push_front(val);
        total += val;
        return total / q.size();
    }
};

/**
 * Your MovingAverage object will be instantiated and called as such:
 * MovingAverage obj = new MovingAverage(size);
 * double param_1 = obj.next(val);
 */