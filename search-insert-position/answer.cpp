
class Solution {
private:
    int search(int A[], int low, int high, int target) {
        int mid, index = -1;
        while (low <= high) {
            mid = (low + high) >> 1;
            if (A[mid] < target) {
                low = mid + 1;
            } else {
                index = mid;
                high = mid - 1;
            }
        }
        if(index == -1)
        	index = high + 1;
        return index;
    }

public:
    int searchInsert(int A[], int n, int target) {
        return search(A, 0, n - 1, target);
    }
};