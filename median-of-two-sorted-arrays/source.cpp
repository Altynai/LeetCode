#include "cstdio"
using namespace std;

class Solution {
private:
    static const int MAX_INT = 0x7fffffff;
    static const int MIN_INT = -0x7fffffff;

    int lessOrEqualCount(int A[], int  n, int val) {
        if (n == 0)
            return 0;
        int low = 0, high = n - 1, mid = 0, index = -1;
        while (low <= high) {
            mid = (low + high) >> 1;
            if (A[mid] <= val) {
                index = mid;
                low = mid + 1;
            } else
                high = mid - 1;
        }
        return index + 1;
    }

    int getValue(int A[], int m, int B[], int n, int index) {
        int low = MIN_INT, high = MAX_INT, mid = 0, count, result = 0;
        while (low <= high) {
            mid = (low + high) >> 1;
            count = lessOrEqualCount(A, m, mid) + lessOrEqualCount(B, n, mid);
            if (count - 1 >= index) {
                result = mid;
                high = mid - 1;
            } else
                low = mid + 1;
        }
        return result;
    }

public:
    double findMedianSortedArrays(int A[], int m, int B[], int n) {
        int total = m + n;
        if (total % 2 == 1)
            return (double)getValue(A, m, B, n, total >> 1);
        else {
            if (total == 0)
                return 0.0;
            double sum = 0;
            sum += getValue(A, m, B, n, total >> 1);
            sum += getValue(A, m, B, n, (total >> 1) - 1);
            return sum * 0.5;
        }
    }
};

int main(int argc, char const *argv[]) {
    Solution *solution = new Solution();
    int A[] = {2}, B[] = {};
    int m = sizeof(A) / sizeof(int);
    int n = sizeof(B) / sizeof(int);
    printf("%.2lf\n", solution->findMedianSortedArrays(A, m, B, n));
    return 0;
}