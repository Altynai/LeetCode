
class Solution {
private:
    int searchForFirst(int A[], int low, int high, int target) {
        int mid, index = -1;
        while (low <= high) {
            mid = (low + high) >> 1;
            if (A[mid] == target){
            	index = mid;
            	high = mid - 1;
            }
            else if (A[mid] < target)
                low = mid + 1;
            else
                high = mid - 1;
        }
        return index;
    }

    int searchForLast(int A[], int low, int high, int target) {
        int mid, index = -1;
        while (low <= high) {
            mid = (low + high) >> 1;
            if (A[mid] == target){
            	index = mid;
            	low = mid + 1;
            }
            else if (A[mid] < target)
                low = mid + 1;
            else
                high = mid - 1;
        }
        return index;
    }

public:
    vector<int> searchRange(int A[], int n, int target) {
    	vector<int> result;
    	result.push_back(searchForFirst(A, 0, n - 1, target));
    	result.push_back(searchForLast(A, 0, n - 1, target));
    	return result;
    }
};