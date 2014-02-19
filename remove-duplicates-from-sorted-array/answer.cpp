
class Solution {
public:
    int removeDuplicates(int A[], int n) {
        if ( n == 0)
            return 0;
        int count = 1, index = 0;
        for (int i = 1; i < n; i++) {
            if (A[i] != A[index]){
            	A[++index] = A[i];
                count++;
            }
        }
        return count;
    }
};