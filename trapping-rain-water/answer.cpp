
class Solution {
public:
    int trap(int A[], int n) {
        if (n == 0)
            return 0;
        int *high_before = new int[n];
        int *index_before = new int[n];
        int *high_after = new int[n];
        int *index_after = new int[n];

        high_before[0] = A[0];
        index_before[0] = 0;
        for (int i = 1; i < n; i++) {
            if (A[i] >= high_before[i - 1]) {
                high_before[i] = A[i];
                index_before[i] = i;
            } else {
                high_before[i] = high_before[i - 1];
                index_before[i] = index_before[i - 1];
            }
        }

        high_after[n - 1] = A[n - 1];
        index_after[n - 1] = n - 1;
        for (int i = n - 2; i >= 0; i--) {
            if (A[i] >= high_after[i + 1]) {
                high_after[i] = A[i];
                index_after[i] = i;
            } else {
                high_after[i] = high_after[i + 1];
                index_after[i] = index_after[i + 1];
            }
        }

        int sum = 0;
        for (int i = 0; i < n; i++)
            sum += std::min(A[index_before[i]], A[index_after[i]]) - A[i];
        return sum;
    }
};