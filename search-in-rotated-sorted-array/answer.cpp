class Solution {
private:
    int findPivot(int A[], int n) {
        for (int i = 1; i < n; i++) {
            if (A[i] < A[i - 1])
                return i - 1;
        }
        return n - 1;
    }

    int search(int A[], int low, int high, int target) {
        int mid;
        while (low <= high) {
            mid = (low + high) >> 1;
            if (A[mid] == target)
                return mid;
            else if (A[mid] < target)
                low = mid + 1;
            else
                high = mid - 1;
        }
        return -1;
    }

public:
    int search(int A[], int n, int target) {
        if (n == 0)
            return -1;
        int pivot = findPivot(A, n);
        int found = search(A, 0, pivot, target);
        if (found != -1)
            return found;
        found = search(A, pivot + 1, n - 1, target);
        return found;
    }
};