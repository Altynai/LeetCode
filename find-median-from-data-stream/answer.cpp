#include <vector>
#include <queue>
#include <cassert>
#include <cstdio>
using namespace std;

class MedianFinder {
private:
    priority_queue<int, vector<int>, greater<int> > min_heap;
    priority_queue<int, vector<int>, less<int> > max_heap;

public:
    MedianFinder() {
        while (!min_heap.empty())
            min_heap.pop();
        while (!max_heap.empty())
            max_heap.pop();
    }

    void adjustTwoHeapSize() {
        while (min_heap.size() > max_heap.size() + 1) {
            max_heap.push(min_heap.top());
            min_heap.pop();
        }
        while (max_heap.size() > min_heap.size() + 1) {
            min_heap.push(max_heap.top());
            max_heap.pop();
        }
    }
    // Adds a number into the data structure.
    void addNum(int num) {
        if (max_heap.size() == 0 || num > max_heap.top())
            min_heap.push(num);
        else
            max_heap.push(num);
        adjustTwoHeapSize();
    }

    // Returns the median of current data stream
    double findMedian() {
        int size = min_heap.size() + max_heap.size();
        if (size % 2 == 1)
            return min_heap.size() > max_heap.size() ? min_heap.top() : max_heap.top();
        return ((double)max_heap.top() + min_heap.top()) * 0.5;
    }
};

// Your MedianFinder object will be instantiated and called as such:
// MedianFinder mf;
// mf.addNum(1);
// mf.findMedian();

int main(int argc, char const *argv[]) {
    MedianFinder mf;
    mf.addNum(1);
    assert(mf.findMedian() == 1.0f);
    mf.addNum(2);
    assert(mf.findMedian() == 1.5f);
    mf.addNum(3);
    assert(mf.findMedian() == 2.0f);
    return 0;
}