#define N 30001
int sum[N << 1];

class Solution {
public:
    int maxSubarraySumCircular(vector<int>& A) {
        int n = A.size(), ma = A[0];
        sum[0] = 0;
        for (int i = 1; i <= n + n; i++)
            sum[i] = sum[i - 1] + A[(i - 1) % n];
        deque<int> dq = {0};
        for (int i = 1; i <= n + n; i++) {
            while (!dq.empty() && sum[i] < sum[dq.front()])
                dq.pop_front();
            dq.push_front(i);
            while (!dq.empty() && dq.back() < i - n)
                dq.pop_back();
            int j = (dq.back() == i) ? i - 1 : dq.back();
            ma = max(ma, sum[i] - sum[j]);
        }
        return ma;
    }
};
