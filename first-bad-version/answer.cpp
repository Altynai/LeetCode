// Forward declaration of isBadVersion API.
bool isBadVersion(int version);

#define i64 long long

class Solution {
public:
    int firstBadVersion(int n) {
        i64 low = 1, high = n, mid = 0;
        int version = 1;
        while (low <= high) {
            mid = (low + high) >> 1;
            if (isBadVersion(mid)) {
                version = mid;
                high = mid - 1;
            } else
                low = mid + 1;
        }
        return version;
    }
};