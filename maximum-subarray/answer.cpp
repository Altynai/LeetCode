
class Solution {
private:
    int maxValue(int A[], int n) {
        int result = A[0];
        for (int i = 1; i < n; i++)
            result = std::max(result, A[i]);
        return result;
    }

public:
    int maxSubArray(int A[], int n) {
    	int max_value = maxValue(A, n);
    	if(max_value <= 0)
    		return max_value;
        int result = 0, sum = 0;
        for (int i = 0; i < n; i++) {
            sum = std::max(sum + A[i], 0);
            result = std::max(result, sum);
        }
        return result;
    }
};