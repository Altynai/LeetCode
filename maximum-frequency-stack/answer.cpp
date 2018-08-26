class FreqStack {
private:
    map<int, int> cnts;
    map<int, deque<int>> nums;
    int level;

public:
    FreqStack() {
        nums.clear();
        cnts.clear();
        level = 1;
    }
    
    void push(int x) {
        int exist = cnts[x]++;
        nums[exist + 1].push_back(x);
        level = max(level, exist + 1);
    }
    
    int pop() {
        deque<int>& dq = nums[level];
        int ans = dq.back();
        cnts[ans]--;
        dq.pop_back();
        if (dq.empty())
            level--;
        return ans;
    }
};

/**
 * Your FreqStack object will be instantiated and called as such:
 * FreqStack obj = new FreqStack();
 * obj.push(x);
 * int param_2 = obj.pop();
 */
