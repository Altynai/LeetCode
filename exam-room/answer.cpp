class ExamRoom {
private:
    int n;
    set<int> seats;

public:
    ExamRoom(int N) {
        n = N;
        seats.clear();
    }

    int seat() {
        if (seats.size() == 0) {
            seats.insert(0);
            return 0;
        }
        int pre = -1, seat = 0, maxd = *seats.begin();
        for (auto it = seats.begin(); it != seats.end(); it++) {
            int cur = *it;
            if (pre != -1) {
                int d = cur - pre;
                if (d / 2 > maxd) {
                    maxd = d / 2;
                    seat = pre + maxd;
                }
            }
            pre = cur;
        }
        if (n - 1 - pre > maxd)
            seat = n - 1;
        seats.insert(seat);
        return seat;
    }

    void leave(int p) {
        seats.erase(p);
    }
};

/**
 * Your ExamRoom object will be instantiated and called as such:
 * ExamRoom obj = new ExamRoom(N);
 * int param_1 = obj.seat();
 * obj.leave(p);
 */
