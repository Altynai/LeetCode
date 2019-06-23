/**
 * // This is MountainArray's API interface.
 * // You should not implement it, or speculate about its implementation
 * interface MountainArray {
 * public int get(int index) {}
 * public int length() {}
 * }
 */

class Solution {
    public int findInMountainArray(int target, MountainArray mountainArr) {
        int n = mountainArr.length();
        int l = 0, r = n - 1;
        while (l < r) {
            int mid = (l + r) >> 1;
            int rmid = (mid + r) >> 1;
            if (mountainArr.get(mid) >= mountainArr.get(rmid))
                r = rmid;
            else
                l = mid;
        }
        int pivot = (mountainArr.get(l) < mountainArr.get(l + 1)) ? l + 1 : l;
        l = 0;
        r = pivot;
        while (l <= r) {
            int mid = (l + r) >> 1;
            int value = mountainArr.get(mid);
            if (value == target)
                return mid;
            else if (value > target)
                r = mid - 1;
            else
                l = mid + 1;
        }
        l = pivot;
        r = n - 1;
        while (l <= r) {
            int mid = (l + r) >> 1;
            int value = mountainArr.get(mid);
            if (value == target)
                return mid;
            else if (value > target)
                l = mid + 1;
            else
                r = mid - 1;
        }
        return -1;
    }
}
