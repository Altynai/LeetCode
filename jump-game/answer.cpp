
class Solution {
public:
    bool canJump(int A[], int n) {
        int farest = 0;
        for (int i = 0; i < n; i++) {
        	if(i > farest)
        		return false;
        	farest = std::max(farest, i + A[i]);
        	if(farest >= n - 1)
        		return true;
        }
        return farest >= n - 1;
    }
};