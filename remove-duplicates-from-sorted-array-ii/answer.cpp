
class Solution {
public:
    int removeDuplicates(int A[], int n) {
        if (n == 0)
            return 0;
        int index = 1, count = 1, value = A[0];
        for (int i = 1; i < n; i++) {
            if (A[i] == value) {
                count += 1;
                if (count <= 2)
                    A[index++] = value;
            } else {
                count = 1;
                value = A[i];
                A[index++] = value;
            }
        }
        return index;
    }
};