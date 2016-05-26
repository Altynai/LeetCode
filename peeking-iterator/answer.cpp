// Below is the interface for Iterator, which is already defined for you.
// **DO NOT** modify the interface for Iterator.
class Iterator {
    struct Data;
    Data* data;
public:
    Iterator(const vector<int>& nums);
    Iterator(const Iterator& iter);
    virtual ~Iterator();
    // Returns the next element in the iteration.
    int next();
    // Returns true if the iteration has more elements.
    bool hasNext() const;
};


class PeekingIterator : public Iterator {
private:
    int index, size;
    const int* ptr;
    const int* init;

public:
    PeekingIterator(const vector<int>& nums) : Iterator(nums) {
        // Initialize any member here.
        // **DO NOT** save a copy of nums and manipulate it directly.
        // You should only use the Iterator interface methods.
        init = ptr = NULL;
        index = -1;
        size = nums.size();
        if (size > 0)
            init = &nums[0];
    }

    // Returns the next element in the iteration without advancing the iterator.
    int peek() {
        const int* next = ptr;
        if (ptr == NULL)
            next = init;
        else
            next++;
        return *next;
    }

    // hasNext() and next() should behave the same as in the Iterator interface.
    // Override them if needed.
    int next() {
        if (ptr == NULL)
            ptr = init;
        else
            ptr++;
        index++;
        return *ptr;
    }

    bool hasNext() const {
        return index + 1 < size;
    }
};